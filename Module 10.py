'''
1.
Write an Elevator class that receives the numbers of the bottom and top floors as initializer parameters.
The elevator has methods go_to_floor, floor_up and floor_down. A new elevator is always at the bottom floor.
If you make elevator h for example the method call h.go_to_floor(5), the method calls either the floor_up or
floor_down methods as many times as it needs to get to the fifth floor. The methods run the elevator one floor up or
down and tell what floor the elevator is after each move. Test the class by creating an elevator in the main program,
tell it to move to a floor of your choice and then back to the bottom floor.
'''

class Elevator:
    def __init__(self, bottom, top, current):
        self.bottom = bottom
        self.top = top
        self.current = current

    def go_to_floor(self, desired_floor):
        self.desired_floor = desired_floor
        if self.current > self.desired_floor:
            h.floor_down()
        elif self.current < self.desired_floor:
            h.floor_up()
        else:
            print(f"You are already on the {h.desired_floor} floor.")

    def floor_up(self):
        while h.current < h.desired_floor:
            print(f"We are at the {h.current} floor.")
            h.current += 1
        print(f"Final stop - {h.desired_floor} -th floor.")

    def floor_down(self):
         while h.current > h.desired_floor:
            print(f"We are at the {h.current} floor.")
            h.current -= 1
         print(f"Final stop - {h.desired_floor}-th floor.")

h = Elevator(0,10, 10)
h.go_to_floor(6)
if int(h.desired_floor) > 0:
    h.go_to_floor(h.bottom)
    print("Lift is on the bottom floor.")
'''
2.
Extend the previous program by creating a Building class. The initializer parameters for the class
are the numbers of the bottom and top floors and the number of elevators in the building.
When a building is created, the building creates the required number of elevators.
The list of elevators is stored as a property of the building. Write a method called run_elevator that
accepts the number of the elevator and the destination floor as its parameters. In the main program,
write the statements for creating a new building and running the elevators of the building.7
'''
import random


class Elevator:
    def __init__(self, bottom, top, current):
        self.bottom = bottom
        self.top = top
        self.current = bottom

    def go_to_floor(self, desired_floor):
        self.desired_floor = desired_floor
        if self.current > self.desired_floor:
            self.floor_down()
        elif self.current < self.desired_floor:
            self.floor_up()
        else:
            print(f"You are already on the {self.desired_floor} floor.")

    def floor_up(self):
        while self.current < self.desired_floor:
            print(f"We are at the {self.current} floor.")
            self.current += 1
        print(f"Final stop - {self.desired_floor} -th floor.")

    def floor_down(self):
         while self.current > self.desired_floor:
            print(f"We are at the {self.current} floor.")
            self.current -= 1
         print(f"Final stop - {self.desired_floor}-th floor.")

class Building:
    def __init__(self, elevators_total):
        self.elevators_total = []
        for i in range(elevators_total):
            self.elevators_total.append(Elevator(0,10 , 0))
           # print("Elevator " + str(i+1) + " is on the " + str(random.randint(0, 10)) + " floor")
        print(f"{elevators_total} elevators were created.")

    def run_elevators(self, which_elevator, desired_floor):
        self.which_elevator = which_elevator
        self.desired_floor = desired_floor
        print(f"Elevator {self.which_elevator} moves to {self.desired_floor} ")
        self.elevators_total[which_elevator - 1].go_to_floor(desired_floor)

building = Building(3)
building.run_elevators(1,5)
building.run_elevators(2,7)
building.run_elevators(3,4)
building.run_elevators(1,9)

'''
3.
Extend the program again by adding a method fire_alarm that does not receive
any parameters and moves all elevators to the bottom floor. Continue the main
program by causing a fire alarm in your building.
'''
class Elevator:
    def __init__(self, bottom, top):
        self.bottom = bottom
        self.top = top
        self.current = bottom

    def go_to_floor(self, desired_floor):
        self.desired_floor = desired_floor
        if self.current > self.desired_floor:
            self.floor_down()
        elif self.current < self.desired_floor:
            self.floor_up()
        else:
            print(f"You are already on the {self.desired_floor} floor.")

    def floor_up(self):
        while self.current < self.desired_floor:
            print(f"We are at the {self.current} floor.")
            self.current += 1
        print(f"Final stop - {self.desired_floor} -th floor.")

    def floor_down(self):
         while self.current > self.desired_floor:
            print(f"We are at the {self.current} floor.")
            self.current -= 1
         print(f"Final stop - {self.desired_floor}-th floor.")

class Building:
    def __init__(self, bottom, top, elevators_total):
        self.bottom = bottom
        self.top = top
        self.elevators_total = []
        for i in range(elevators_total):
            self.elevators_total.append(Elevator(self.bottom, self.top))
           # print("Elevator " + str(i+1) + " is on the " + str(random.randint(0, 10)) + " floor")
        print(f"{elevators_total} elevators were created.")

    def run_elevators(self, which_elevator, desired_floor):
        self.which_elevator = which_elevator
        self.desired_floor = desired_floor
        print(f"Elevator {self.which_elevator} moves to {self.desired_floor} ")
        self.elevators_total[which_elevator - 1].go_to_floor(desired_floor)

    def fire(self):
        print("FIRE IN THE BUILDING!")
        n = 1
        for i in self.elevators_total:
            i.go_to_floor(self.bottom)
            print(f"Elevator {n} is on the bottom floor.")
            n += 1


building = Building(1, 7, 3)
building.run_elevators(1,5)
building.run_elevators(2,7)
building.run_elevators(3,4)
building.run_elevators(1,6)
building.fire()



