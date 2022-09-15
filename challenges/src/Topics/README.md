## Topics 

#### ROS Topics:

  - A topic is a named bus over which nodes exchange messages
  - It's a unidirectional data stream (publisher/subscriber)
  - It's anonymous (A subscriber doesn't know if there are other subscribers listening to the same publisher and the same for publishers)
  - It has a message type
  - The ROS master helps nodes finding needed topics

#### The challenge:

Create two nodes with the following features:
  - The first node, the number publisher, will publish to a topic "number" with the message type (std_msgs/Int64);
  - Then a number counter node, that will contain both a subscriber and a publisher, it will subscribe to the topic number and store the number inside a content. So that every time it receives a number, it will add it to a counter. And every time it increases the number, it will publish on the topic "number_count" with the same message type;
  - Additionally, I've created a subscriber just to print the results to the terminal (number_subscriber);


![Screenshot from 2022-09-15 14-56-44](https://user-images.githubusercontent.com/74921179/190422907-edb66a24-5a00-4f9f-a943-043f8352f9e4.png)
