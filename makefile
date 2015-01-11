#	Computer Graphics coursework
# 	Daniel Bergmann - db0763
#	db0763@my.bristol.ac.uk

# compilers
cc		= clang++
# cc		= g++

# flags
cflags := -std=c++0x \
			-Wall \
			-g \
			-Wfatal-errors \
			-pedantic \
			-I./src

lflags = 

cflags	:= $(cflags)
libs	=

# output binary file
bin		= raytracer
# source files
src		=	Raytracer.cpp \
			Camera.cpp \
			Image.cpp \
			main.cpp \
			Scene.cpp \
			Vector3.cpp \
			\
			BoundingTree/Node.cpp \
			\
			Geometry/Object.cpp \
			Geometry/Sphere.cpp \
			Geometry/Plane.cpp \
			Geometry/Triangle.cpp \
			\
			Light/Colour.cpp \
			Light/Ray.cpp \
			Light/Light.cpp \
			Light/DirectionalLight.cpp \
			Light/PointLight.cpp \
			Light/SpotLight.cpp \
			\
			Material/Material.cpp \
			Material/DiffuseColour.cpp \
			Material/Lambert.cpp \
			Material/Specular.cpp

# recalculated object files and source files to take account of the src and obj path prefixes.
obj := $(addprefix obj/, $(addsuffix .o,$(basename $(src))))
src := $(addprefix src/, $(src))

#

all: clear $(bin)

clear:
	clear

# link the binary
$(bin): check-paths $(obj)
	$(cc) $(lflags) $(obj) -o $(bin) $(libs)

# compile to object
$(obj): obj/%.o : src/%.cpp
	$(cc) $(cflags) -o $@ -c $^

# check that the relevant object directories exist
check-paths:
	@mkdir -p $(dir $(obj))

# clean intermediate files
clean:
	rm -Rf $(bin) obj/*
