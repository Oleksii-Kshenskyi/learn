#pragma once

#include "turtlesim/msg/pose.hpp"
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

namespace turtle_autopilot {
    class AutopilotNode final: public rclcpp::Node {
        public:
            AutopilotNode();
        private:
            void on_timer();
            void on_pose(turtlesim::msg::Pose::ConstSharedPtr message);

            rclcpp::TimerBase::SharedPtr timer;
            std::size_t tick_count {0};

            rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub;
            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub;

            turtlesim::msg::Pose latest_pose;
            bool received_pose {false};

            double target_x;
            double target_y;
    };
}