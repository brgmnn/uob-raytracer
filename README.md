# Raytracer #
<sup>2013</sup>

![A Disco Snowman](renders/snowman-disco.png "Disco Snowman")

A graphics raytracer, which was used to render the disco snowman above! Some features:

* Moveable camera and generation of BMP images.
* Primitives: planes, spheres and triangles (though there is a bug with the
    material shading at the moment).
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

### Compiling ###

Compile the raytracer with:

```
make all
```

### Some more pictures ###

Below are some more pictures I rendered using my raytracer.

![A sphere with coloured lights, shadows, reflections.](renders/cool-disco-shadows.png "Disco Sphere")
![Spheres with shadows and recursive reflections.](renders/spheres-shadows-recursive-reflections.png "Recursive shadows")
![A point light.](renders/point-light.png "Point Light")
![A triangle primitive.](renders/triangle-reflection-shadows.png "Triangle Reflection")
![Merged spheres.](renders/ambient.bmp "Ambient lighting")
