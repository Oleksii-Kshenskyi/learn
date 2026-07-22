#include <memory>
#include <rclcpp/rclcpp.hpp>
#include "turtle_autopilot/autopilot_node.hpp"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<turtle_autopilot::AutopilotNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}