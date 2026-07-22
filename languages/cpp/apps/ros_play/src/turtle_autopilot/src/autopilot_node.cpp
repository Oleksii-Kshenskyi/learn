#include "turtle_autopilot/autopilot_node.hpp"
#include "turtlesim/msg/pose.hpp"
#include <chrono>
#include <algorithm>
#include <cmath>

namespace turtle_autopilot {
    AutopilotNode::AutopilotNode(): rclcpp::Node("turtle_autopilot") {
        RCLCPP_INFO(get_logger(), "Turtle autopilot started.");

        this->timer = create_wall_timer(std::chrono::milliseconds {100}, [this]{
            on_timer();
        });

        this->pose_sub = create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, [this](turtlesim::msg::Pose::ConstSharedPtr message) {
            this->on_pose(message);
        });

        this->cmd_vel_pub = create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

        this->target_x = declare_parameter<double>("target_x", 1.0);
        this->target_y = declare_parameter<double>("target_y", 1.0);

        RCLCPP_INFO(get_logger(), "[AUTOPILOT CONSTRUCT] Target set as (%.2f, %.2f);", this->target_x, this->target_y);
    }

    void AutopilotNode::on_timer() {
        if(!this->received_pose) {
            RCLCPP_INFO(get_logger(), "[AutopilotNode::on_timer()] Waiting for turtle pose...");
            return;
        }

        const double dx = this->target_x - this->latest_pose.x;
        const double dy = this->target_y - this->latest_pose.y;

        const double distance = std::hypot(dx, dy);
        const double desired_heading = std::atan2(dy, dx);

        const double raw_heading_error = desired_heading - this->latest_pose.theta;

        const double heading_error = std::atan2(
            std::sin(raw_heading_error),
            std::cos(raw_heading_error)
        );

        geometry_msgs::msg::Twist cmd;

        constexpr double arrival_tolerance = 0.1;

        if (distance < arrival_tolerance) {
            this->cmd_vel_pub->publish(cmd);

            ++this->tick_count;
            if(this->tick_count % 10 == 0) {
                RCLCPP_INFO(
                    get_logger(),
                    "[DONE] Target reached: x=%.2f, y=%.2f",
                    this->latest_pose.x,
                    this->latest_pose.y
                );
            }

            return;
        }

        cmd.angular.z = std::clamp(4.0 * heading_error, -4.0, 4.0);

        if(std::abs(heading_error) < 0.5) {
            cmd.linear.x = std::clamp(distance, 0.0, 2.0);
        }

        this->cmd_vel_pub->publish(cmd);
        ++this->tick_count;
        if(this->tick_count % 10 == 0) {
            RCLCPP_INFO(
                get_logger(),
                "[MOVING] Position=(%.2f, %.2f), distance=%.2f, heading error=%.2f",
                this->latest_pose.x,
                this->latest_pose.y,
                distance,
                heading_error);
        }
    }

    void AutopilotNode::on_pose(turtlesim::msg::Pose::ConstSharedPtr message) {
        this->latest_pose = *message;
        this->received_pose = true;
    };
}