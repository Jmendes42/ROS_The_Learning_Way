# Launch File

### ROS Launch File

  - Can be used to set ROS parameters
  - Can also be used to start ROS nodes

#### Notes:

Create a package just for launch files to simplify. Use the `catkin_create_pkg` without dependencies

`catkin_create_pkg <file_name>`

![Screenshot from 2022-09-15 18-21-26](https://user-images.githubusercontent.com/74921179/190469924-68553634-dd68-4a88-9886-b5817d3b2cc0.png)

After `catkin_make` in the workspace root folder

Then, create a `.launch` file with the configurations

Use the `roslaunch` command to start the launch file

`roslaunch <package_name> <file_name>`

or, inside the launch folder `roslaunch <file_name>`

![Screenshot from 2022-09-15 18-48-45](https://user-images.githubusercontent.com/74921179/190474849-89053219-64c5-4c1b-9f19-d40b5997ed84.png)
