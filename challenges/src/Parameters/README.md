## Parameters

### ROS Parameters

  - When a ROS master is started, a parameter server is also started
  - ROS Parameter is one shared variable stored inside the parameter server
  - Parameter server is dictionary inside ROS master, accessible globally
  - ROS Parameter type:
      - Boolean
      - Int
      - Double
      - String
      - Lists
      - ...

#### Challenge:

  - Adapt the Topics challenges to use the ROS Parameters

#### Notes:

 Parameters can be set through the command line with the command `rosparam set <param_name> <param_content>` or through specific functions in the nodes
 
 Command line commands:
 
 ![Screenshot from 2022-09-15 19-08-27](https://user-images.githubusercontent.com/74921179/190478197-5ea54e77-350a-4639-9e97-375d4217d724.png)
