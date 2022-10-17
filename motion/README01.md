#### Notes:

Use the Turtlesim simulator to test these topics.

To use it, run the command ```rosrun``` with ```turtlesim turtlesim_node``` to initiate the turtlesim node.

```rosrun <package> <node>```

![simCommand](https://user-images.githubusercontent.com/74921179/193732692-68fc9c3a-95aa-4cb0-a02e-215d32bc1deb.png)

The simulator window will pop up

![smallturtle](https://user-images.githubusercontent.com/74921179/193732750-7ffc2875-0f10-4202-a8e0-4dfca79eba8e.png)

To discover which topics to publish and subscribe (the pose(/turtle1/pose) and velocity(/turtle1/cmd_vel)) run the command ```rostopic list```

![list](https://user-images.githubusercontent.com/74921179/193733074-d612ed2e-51c7-4014-bbf7-c549443e5358.png)

To use them, it's required to know which messages types they use, and the parameters of the message types.

For that run the command ```rostopic info``` on target topics ```/turtle1/pose``` and  ```/turtle1/cmd_vel``` to show the message type, next run the command ```rosmsg show``` on types ```geometry_msgs/Twist``` and ```turtlesim/Pose```

```rostopic info <targetNode>```

```rosmsg show <targetMsg>```

![msgShow](https://user-images.githubusercontent.com/74921179/193733598-71123663-252e-40a4-844f-3bca9d6416e9.png)

