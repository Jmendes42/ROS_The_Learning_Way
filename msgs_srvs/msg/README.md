## Custom Messages

#### Notes:

To create a custom message, add the following lines to the `package.xml` inside the package:

`<build_depend>message_generation</build_depend>`

`<exec_depend>message_runtime</exec_depend>`

![Screenshot from 2022-09-15 15-41-56](https://user-images.githubusercontent.com/74921179/190433723-da11c3e4-a8b7-4388-9b88-cfec2c9b777a.png)

Then in the `CMakeLists.txt` file:

- Add `message_generation` to the `find_package` zone

![Screenshot from 2022-09-15 15-56-18](https://user-images.githubusercontent.com/74921179/190437223-10cda0f0-4ae7-4393-af70-80d5e8a1d2b5.png)

- Uncomment the `Generate added messages and services` zone 

![Screenshot from 2022-09-15 16-01-46](https://user-images.githubusercontent.com/74921179/190438588-bd3a6517-cafa-42ac-a858-383f09756842.png)

- Next, in the `catkin_package` zone, uncomment the `CATKIN_DEPENDS roscpp rospy std_msgs` and add `message_runtime`

![Screenshot from 2022-09-15 16-12-39](https://user-images.githubusercontent.com/74921179/190441064-6e57af64-b6c6-4942-842c-ff5bee94c7ea.png)

- Create a msg folder and the `.msg` file inside 
- After the `.msg` file is created return to the `CMakeLists.txt`, uncomment the `Generate messages in the 'msg' folder` zone, remove the template files and add the created one

![Screenshot from 2022-09-15 16-18-25](https://user-images.githubusercontent.com/74921179/190442376-1f147f19-5be1-4b15-a5f7-74ef7f923db9.png)

- To finish, use `catkin_make` on the workspace root file.

