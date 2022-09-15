## Custom Messages and Services

*See msgs_srvs package folder

#### Challenge:

  - Create a battery node that contains a battery state and will publish it;
  - Create a LED panel which will contain the state of the three LEDs and will print the state ("[1,1,1]" - all LEDs up, "[0,0,0]" - all LEDs down);
  - Create a new service definition to power off or on the LEDs
  - Additionally, I also created a battery status subscriber to receive the battery status and ask for the service to the LED panel node;
  
  
![Screenshot from 2022-09-15 17-53-50](https://user-images.githubusercontent.com/74921179/190462866-5b8ed410-83a3-4a64-88cb-c4da359db9f5.png)


#### Notes:

To add custom packages dependencies add the folder name to `CMakeLists.txt` file:

![Screenshot from 2022-09-15 13-52-40](https://user-images.githubusercontent.com/74921179/190408553-0b625195-c16e-4c9e-93a3-1ff5250f5126.png)

And to `package.xml` add:

![Screenshot from 2022-09-15 14-00-56](https://user-images.githubusercontent.com/74921179/190410967-b5028a80-19d2-4f49-978d-37fad40d4e9d.png)

`<depend>package_name</depend>` is the same as `<buildtool_depend>` + `<build_depend>` + `<exec_depend>`
