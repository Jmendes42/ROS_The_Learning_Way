## Custom Messages and Services

*See msgs_srvs package folder


#### Notes:

To add custom or standard packages dependencies add the folder name to `CMakeLists.txt` file:

![Screenshot from 2022-09-15 13-52-40](https://user-images.githubusercontent.com/74921179/190408553-0b625195-c16e-4c9e-93a3-1ff5250f5126.png)

And to `package.xml` add:

![Screenshot from 2022-09-15 14-00-56](https://user-images.githubusercontent.com/74921179/190410967-b5028a80-19d2-4f49-978d-37fad40d4e9d.png)

`<depend>package_name</depend>` is the same as `<buildtool_depend>` + `<build_depend>` + `<exec_depend>`
