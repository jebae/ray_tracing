# Ray tracing in c++

![ray_tracing](https://www.dropbox.com/s/t0oci4oelv5fmou/ray_tracing.png?raw=1)

**ray_tracing** is good example to learn basics for ray tracing. In this project we can learn,

- Object intersection
- Getting normal vector from intersection point
- Phong model
	- diffuse
	- specular
- Reflection
- Refraction

<br><br>

## Features

- Sphere, cone, cylinder, plane
	- [sphere.hpp](includes/sphere.hpp) [sphere.cpp](srcs/object/sphere.hpp)
	- [cone.hpp](includes/cone.hpp) [cone.cpp](srcs/object/cone.hpp)
	- [cylinder.hpp](includes/cylinder.hpp) [cylinder.cpp](srcs/object/cylinder.hpp)
	- [plane.hpp](includes/plane.hpp) [plane.cpp](srcs/object/plane.hpp)

<br>

- Phong model
	- [shade.hpp](includes/shade.hpp) [shade.cpp](srcs/shade/shade.hpp)

<br>

- Shadow
	- [shade.hpp](includes/shade.hpp) [shade.cpp](srcs/shade/shade.hpp)

<br>

- Distant & spherical light
	- [distant_light.hpp](includes/distant_light.hpp) [distant_light.cpp](srcs/light/distant_light.hpp)
	- [spherical_light.hpp](includes/spherical_light.hpp) [spherical_light.cpp](srcs/light/spherical_light.hpp)

<br>

- Reflection & refraction
	- [tracer.hpp](includes/tracer.hpp) [tracer.cpp](srcs/trace/tracer.hpp)

<br><br>

> **INFO** This project doesn't give tool for window open and event handling. Recommended to install such library.
e.g. OpenGL, Vulkan, SDL
