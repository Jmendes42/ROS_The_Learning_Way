#include "motion.hpp"

Motion	*_getMotion() {
	static Motion	m;
	return &m;
}

void	poseCallback(const turtlesim::Pose &poseMessage) {
	_getMotion()->_poseCallback(poseMessage);
}

int		main(int argc, char **argv ){
	
	turtlesim::Pose	moveTo;
	double			answer[2];
	Motion			*motion = _getMotion();

	ros::init(argc, argv, "turtlesim_move");
	ros::NodeHandle nh;

	motion->_publisherSet(nh);
	moveTo.theta = 0;

	while (ros::ok()) {
		motion->_getSubscriber() = nh.subscribe("/turtle1/pose", 10, poseCallback);
		std::cout << "Insert desired position X and Y, or 0 to leave" << std::endl;
		std::cin >> answer[0];
		if (answer[0] == 0)
			break;
		std::cin >> answer[1];
		moveTo.y = answer[0];
		moveTo.x = answer[1];
		motion->_goToGoal(moveTo, 0.1);
		ros::spinOnce();
	}
}
