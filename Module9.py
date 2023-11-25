"""
1.
Write a Car class that has the following properties: registration number, maximum speed, current speed and travelled distance..
Add a class initializer that sets the first two of the properties based on parameter values.
The current speed and travelled distance of a new car must be automatically set to zero.
Write a main program where you create a new car (registration number ABC-123, maximum speed 142 km/h).
Finally, print out all the properties of the new car.
"""

class Car:
    def __init__(self, reg_number, max_sped, current_speed = 0, travelled_distance = 0):
        self.reg_number = reg_number
        self.max_speed = max_sped
        self.current_speed = current_speed
        self.travelled_distance = travelled_distance

car = Car("ABC - 123", "142 km/h")
print(f"This car's registration number is {car.reg_number} and its maximum speed is {car.max_speed}.")

"""
2.
Extend the program by adding an accerelate method into the new class.
    The method should receive the change of speed (km/h) as a parameter.
    If the change is negative, the car reduces speed. The method must change the value of the speed property of the object.
    The speed of the car must stay below the set maximum and cannot be less than zero.
    Extend the main program so that the speed of the car is first increased by +30 km/h, then +70 km/h and finally +50 km/h.
    Then print out the current speed of the car.
    Finally, use the emergency brake by forcing a -200 km/h change on the speed and then print out the final speed.
    The travelled distance does not have to be updated yet.
"""

class Car:
    def __init__(self, reg_number, max_speed, current_speed = 0, travelled_distance = 0):
        self.reg_number = reg_number
        self.max_speed = max_speed
        self.current_speed = current_speed
        self.travelled_distance = travelled_distance

    def accelerate(self,speed_change):
        self.speed_change = speed_change
        self.current_speed = self.current_speed + self.speed_change
        if self.current_speed < 0 or self.current_speed > self.max_speed:
            print(f"{self.current_speed} km/h!!! Check the speed!!!")
        else:
            print(f"Current speed is {car.current_speed} km/h ")


car = Car("ABC - 123", 142 )
car.accelerate(30)
car.accelerate(70)
car.accelerate(50)
car.accelerate(-200)

"""
3.
Again, extend the program by adding a new drive method that receives the number of hours as a parameter.
The method increases the travelled distance by how much the car has travelled in constant speed in the given time.
Example: The travelled distance of car object is 2000 km. The current speed is 60 km/h. Method call car.drive(1.5) increases the travelled distance to 2090 km.
"""

class Car:
    def __init__(self, reg_number, max_speed, current_speed = 0, travelled_distance = 0):
        self.reg_number = reg_number
        self.max_speed = max_speed
        self.current_speed = current_speed
        self.travelled_distance = travelled_distance

    def accelerate(self,speed_change):
        self.speed_change = speed_change
        self.current_speed = self.current_speed + self.speed_change
        if self.current_speed < 0 or self.current_speed > self.max_speed:
            print(f"{self.current_speed} km/h!!! Check the speed!!!")
        else:
            print(f"Current speed is {car.current_speed} km/h ")
    def drive(self, hours):
        self.hours = hours
        car.travelled_distance = (self.current_speed * self.hours) + self.travelled_distance
        print(f"Travelled distance is {car.travelled_distance} km.")

car = Car("ABC-123", 150, 60, 2000)
car.accelerate(50)
car.drive(1.5)

"""
4.
Now we will program a car race. The travelled distance of a new car is initialized as zero.
At the beginning of the main program, create a list that consists of 10 car objects created using a loop.
The maximum speed of each new car is a random value between 100 km/h and 200 km/h.
The registration numbers are created as follows: "ABC-1", "ABC-2" and so on. Now the race begins.
One per every hour of the race, the following operations are performed:
The speed of each car is changed so that the change in speed is a random value between -10 km/h and +15 km/h.
This is done using the accerelate method.
Each car is made to drive for one hour. This is done with the drive method.
The race continues until one of the cars has advanced at least 10,000 kilometers.
Finally, the properties of each car are printed out formatted into a clear table.
"""

import random

class Car:
    def __init__(self, reg_number, max_speed, current_speed, travelled_distance):
        self.reg_number = reg_number
        self.max_speed = max_speed
        self.current_speed = current_speed
        self.travelled_distance = travelled_distance

    def accelerate(self, acceleration):
        self.acceleration = acceleration
        self.current_speed = min(max(self.current_speed + self.acceleration, 0), self.max_speed)


    def drive(self, hours):
        self.hours = hours
        car.travelled_distance = (self.current_speed * self.hours) + self.travelled_distance

car_list = []
for i in range(10):
    car_list.append(Car("ABC-" + str(i+1), random.randint(100, 200),0 ,0))

finish = 0
while finish < 10000:
    for car in car_list:
        car.accelerate(random.randint(-10, 15))
        car.drive(1.)
        finish = max(car.travelled_distance, finish)

for car in car_list:
    print(f"This car's registration number: {car.reg_number} and maximum speed is {car.max_speed}, "
              f"current speed is {car.current_speed}, travelled distance is {car.travelled_distance}")



