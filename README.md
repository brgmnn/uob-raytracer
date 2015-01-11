# Raytracer #
<sup>2013</sup>

![A Disco Snowman](renders/snowman-disco.png?raw=true "Disco Snowman")

A graphics raytracer, which was used to render the disco snowman above! Some features:

* Moveable camera and generation of BMP images.
* Primitives: planes, spheres and triangles (though there is a bug with the
    triangle material shading at the moment).
* Shadows.
* Reflections (recursive reflections).
* Lighting: ambient light, point lights and spot lights. All in different
    colours.
* Materials: lambertian and specular materials.
* Accelerated rendering by storing objects in a bounding volume hierarchy.

Some things that would be fun to add:

* Transparent materials.
* Texture maps.

### Dependencies ###

* Gtest.
* GCC.

### Compiling and running ###

Compile the raytracer with:

```
make all
```

Run the raytracer with:

```
./raytracer
```

This should render and create the `snowman-disco.bmp` image in the current
folder.

### Some more pictures ###

Below are some more pictures I rendered using my raytracer.

![A sphere with coloured lights, shadows, reflections.](renders/cool-disco-shadows.png?raw=true "A sphere with coloured lights, shadows, reflections.")
![Spheres with shadows and recursive reflections.](renders/spheres-shadows-recursive-reflections.png?raw=true "Spheres with shadows and recursive reflections.")
![A point light.](renders/point-light.png?raw=true "A point light.")
![A triangle primitive.](renders/triangle-reflection-shadows.png?raw=true "A triangle primitive.")
![Merged spheres.](renders/ambient.bmp?raw=true "Merged spheres.")
