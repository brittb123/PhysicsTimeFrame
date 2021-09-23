# Getting Started:

## What is this program:
This is a program that uses formulas and physics to simulate the closest possible representation 
to real life physics by showing the three laws made by Isaac Newton! 

## Running the program and how to use:

First off make sure to download and open the folder then open the folder *Physics in Bootstrap*.
Once the folder is opened open the folder named *Physics Simulation Executable* and double click the 
exe named *Physics Project* and watch the simulation! 

### Keys to know:

#### Pressing the escape key:
Once you press the escape key the project closes!

#### Pressing the R key:
Pressing the R key restarts the simulation from teh beginning and can be done whenever pleased!

# Important Classes, Functions, and Variables:

This is the section where all the very important classes, functions, and variables used in the program are shown and 
describe how they are used! The classes will be split up and the functions will have the visibilty, name, type, parameters, and 
description that are in their respective class! The variables will be split into their classes as well as have the visibilty, name, 
the type, and a description of what it is used for!

## RigidBody Class:

#### Important Variables:
Name: m_position

Type: Vector2

Visibility: Private

Desciption: A simple variable that holds the position of the object that has the rigid body!

 -----------------------------------------------------------------------------------------------

Name: m_velocity

Type: Vector2

Visibility: Private

Desciption: A variable that holds the velocity of the object with the rigid body!

-----------------------------------------------------------------------------------------------------

Name: m_orientation

Type: Float

Visibility: Private

Desciption: The variable that holds the rotation of the object!


-----------------------------------------------------------------------------------------------------

Name: m_mass

Type: Float

Visibility: Private  

Desciption: The mass given to the object.



#### Important Functions:

Name: RigidBody(ShapeType ShapeID, glm::vec2 position, glm::vec2 velocity, float orientation, float mass)

Type: Constructor

Visibility: Public

Desciption: This is the basic constructor that takes in a shape id for the shape of the object, 
a vector2 position to have a position on the grid,  a vector2 for the velocity to have a holder for the velocity of the object,
a float that holds the rotation of the object,  and a float to give the object a certain mass!

-----------------------------------------------------------------------------------------------------

Name: ~RigidBody()

Type: Deconstructor

Visibility: Public

Desciption: A simple deconstructor that usually removes unwanted excess but, not used in this class!

-----------------------------------------------------------------------------------------------------

Name: fixedUpdate(glm::vec2 gravity, float timeStep)

Type: Virtual Void

Visibility: Public

Desciption: A simple function called every frame update that moves the object by altering the position
if needed and applies a force to this object when needed!

-----------------------------------------------------------------------------------------------------

Name: applyForce(glm::vec2 Force)

Type: Void

Visibility: Public

Desciption: A function that gives an object a force when collided or needed to be exerted on a object by calculating the acceleration and adding the velocity to it!

-----------------------------------------------------------------------------------------------------

Name: applyForceToOther(RigidBody* other, glm::vec2 force)

Type: Void

Visibility: Public

Desciption: This function is used when a collision happens by using the applyForce() function to the other object and
applies the opposite force to the object colliding. 
  
-----------------------------------------------------------------------------------------------------

Name: resolveCollision(RigidBody* other)

Type: Void

Visibility: Public

Desciption: A function that calculates the impulses of the collision and applies the 
impuleses to the objects. This impulse has a very detailed calculation by finding the dot product of the
opposite of 1 + elasticity times the velocty and  the collision normal! Take that dot product and divide it by the dot product
of the collision normal and the collision normal times 1 divided by the mass of both objects and add the two quotient together! 


## PhysicsObject Class:

#### Important Variables:

Name: m_shapeID

Type: ShapeType

Visibility: private

Desciption: The shape type of the object which can be a sphere or plane!

#### Important Functions:

Name: PhysicsOnject(ShapeType shapeID)

Type: Constructor

Visibility: Protected

Desciption: A constructor that assigns the object the shape type of the desired object.
The two shape types possible is either a sphere or a plane!

-----------------------------------------------------------------------------------------------------

Name: fixedUpdate(glm::vec2 gravity, float timeStep)

Type: Virtual Void

Visibility: public

Desciption: This makes the funtion abstract which has to be used in every class that inherents this class!
This function is used to update the object's position and forces by using the time step which updates when it hits the mark 
and using gravity to have more realistic physics when applying the force!

-----------------------------------------------------------------------------------------------------

Name: draw()

Type: Virtual Void 

Visibility: Public

Desciption: This function is a abstract function which requires it to be defined in any class that inherients.
This function is used to draw any shape or object that is used in the scene!

## Sphere Class:

#### Important Variables:

Name: m_radius

Type: Private

Visibility: Private

Desciption: This is a simple variable used to have the radius of the sphere stored and set!

-----------------------------------------------------------------------------------------------------

Name: m_color

Type: Vector4

Visibility: Private

Desciption: A vector4 to assign the color of the sphere using the four values!

#### Important Function:

Name: Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)

Type: Constructor

Visibility: Public

Desciption: The constructorthat gives the sphere a position and a velocity using a vector2, and assigns 
a mass, radius, and color to the sphere!

-----------------------------------------------------------------------------------------------------

Name: draw()

Type: Vitual Void

Visibility: Public

Desciption: A function that draws the object onto the scene using gizmos! 

## Plane Class:

#### Important Variables:

Name: m_normal

Type: Vector2

Visibility: Private

Desciption: The normal of the plane is the facing direction and is stored in this variable

-----------------------------------------------------------------------------------------------------

Name: m_distance

Type: Float

Visibility: Private

Desciption: The distance of the plane on the grid from the origin!

-----------------------------------------------------------------------------------------------------

Name: m_color

Type: Vector4

Visibility: Private

Desciption: A vector4 that gives the plane color using the four values of the vector!
   
#### Important Functions:

Name: Plane(glm::vec2 normal, float distance, glm::vec4 color)

Type: Constructor

Visibility: Public

Desciption: The constructor that creates and gives the plane a specific normal, distance and color
using the parameters!

-----------------------------------------------------------------------------------------------------

Name: fixedUpdate()

Type: Virtual Void

Visibility: Public

Desciption: A function called every frame that updates the velocity using the gravity and acceleration 
while using time step to get the time when to update!

-----------------------------------------------------------------------------------------------------

Name: draw()

Type: Virtual Void

Visibility: Public

Desciption: This function is called when a object needs to be drawn to the scene by
drawing the line witha  gizmos!

## PhysicsScene Class:

#### Important Variables:

Name: m_gravity

Type: Vector2

Visibility: Private

Desciption: A variable that holds the gravity value to be applied to the scene when used!

-----------------------------------------------------------------------------------------------------

Name: m_timeStep 

Type: Flaot

Visibility: Private 

Desciption: The timestep variable is used to update the frame when it reaches that specific value and 
then is subtracted from the time of the program being ran!

-----------------------------------------------------------------------------------------------------

Name: m_actors

Type: PhysicsObject*

Visibility: Private

Desciption: This is a list of actors that is added to the scene to be accessed
and when needed removed from the scene!

#### Important Functions: 

Name: PhysicsScene() 

Type: Constructor

Visibility: Public

Desciption: A basic constructor that is called to make a new scene and hold all the information that is needed such as 
the gravity, timestep, and the list of actors!
 
-----------------------------------------------------------------------------------------------------

Name: addActor(PhysicsObject* actor)

Type: Void

Visibility: Public 

Desciption: A simple function that calls the insert function to put the passed in object 
into the list of the actors!

-----------------------------------------------------------------------------------------------------

Name: removeActor(PhysicsObject* actor) 

Type: Void

Visibility: Public 

Desciption: A function that simply erases the actor that is passed into the 
function!

-----------------------------------------------------------------------------------------------------

Name: update(float deltatime)

Type: Void

Visibility: Public

Desciption: A function that is used every frame that updates every actor and the scene by 
adding the float deltatime toa another float accumalted time and when it is over the desired time step 
accumlated time is subtracted and the scene and the actors inside the scene are updated!

-----------------------------------------------------------------------------------------------------

Name: draw()

Type: Void

Visibility: Public 

Desciption: The simple function called every update that uses the objects draw functions and draws all in the 
scene that is added!

-----------------------------------------------------------------------------------------------------

Name: setGravity(const glm::vec2 gravity)

Type: Void

Visibility: Public 

Desciption: A simple function that sets the gravity variable equal to the passed in values!

-----------------------------------------------------------------------------------------------------

Name: setTmeStep(const float timeStep)

Type: Void

Visibility: Public

Desciption: A function that takes a passed in float and sets the timestep variable
to equal the passed in flaot!

-----------------------------------------------------------------------------------------------------

Name: sphereToPlane(PhysicsObject* object1, PhysicsObject* object2)

Type: Static Bool

Visibility: Public

Desciption: A function that takes in the two objects and uses a dynamic cast to set the object as the shape. A if check is then used
to see the cast was failed ending it up to be null. If the cast was successful the dot product of the
center of the sphere and the plane normal is grabbed! The value of that dot product is subtracted by the planeDistance and the sphere radius 
for more exact collision detection! If the value is less then or equal to zero, then
the function resolveCollision(Sphere) is called!

-----------------------------------------------------------------------------------------------------

Name: sphereToSphere(PhysicsObject* object1, PhysicsObject2* object2) 

Type: Static Bool

Visibility: Public

Desciption: This function takes two PhysicsObject references and casts them like the sphereToPlane() function.
If the cast was successful the positions of both sphere are retrieved and are calculated to find the distance
between both spheres. After, both spheres' radii are added and if greater then the distance found
the first sphere's resolveCollision function is called !
 
  

# Outside Sources:

## Bootstrap: 
The one and only source for making the program was Bootstrap from this repository from github!
[Click here to go to Bootstrap Repository](https://github.com/AcademyOfInteractiveEntertainment/aieBootstrap)