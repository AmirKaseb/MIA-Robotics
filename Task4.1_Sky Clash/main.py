##-----------AmirKasseb-----------##
##-----------25/8/2023------------##
##-------TASK4.1- Sky Clash ------##

import random

# Define the weapon classes with their attributes.
class FreezeGun:
    damage = 10
    special_effect = "reduce next opponent attack"

class ElectricProd:
    damage = 8
    special_effect = None

class MegaMagnet:
    damage = 12
    special_effect = None

class KalmanMissile:
    damage = 15
    special_effect = None

# Define the shield classes with their attributes.
class EnergyProjectedBarrierGun:
    cost = 5
    save_percentage = 0.5

class SelectivePermeability:
    cost = 3
    save_percentage = 0.3

class EnergyNetTrap:
    cost = 4
    save_percentage = 0.4

class QuantumDeflector:
    cost = 6
    save_percentage = 0.6

# Define the base Villain class.
class Villain:
    def __init__(self, name, health, energy, shield):
        # Initialize the Villain object with name, health, energy, and shield attributes.
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = shield

    def attack(self, opponent):
        # Choose a random weapon from the villain's inventory.
        weapon = random.choice(self.weapons)
        # Generate a random amount of damage within the weapon's damage range.
        damage = random.randint(0, weapon.damage)
        # If the weapon's special effect is "reduce next opponent attack", decrease the opponent's shield.
        if weapon.special_effect == "reduce next opponent attack":
            opponent.shield -= damage * 0.2
        else:
            # Otherwise, deduct the damage directly from the opponent's health.
            opponent.health -= damage

    def defend(self):
        # Choose a random shield from the villain's inventory.
        shield = random.choice(self.shields)
        # Reduce the villain's energy by the shield's cost.
        self.energy -= shield.cost
        # Set the villain's shield to the minimum of their health and the shield's save percentage.
        self.shield = min(self.health, shield.save_percentage * self.health)

    def is_dead(self):
        # Return True if the villain's health is 0 or below.
        return self.health <= 0

# Define the Gru subclass which inherits from Villain.
class Gru(Villain):
    weapons = [FreezeGun, ElectricProd, MegaMagnet, KalmanMissile]
    shields = [EnergyProjectedBarrierGun, SelectivePermeability]

# Define the Vector subclass which inherits from Villain.
class Vector(Villain):
    weapons = [FreezeGun, ElectricProd, MegaMagnet, KalmanMissile]
    shields = [EnergyNetTrap, QuantumDeflector]

# Define the main function.
def main():
    # Create Gru and Vector instances with their initial attributes.
    gru = Gru("Gru", 100, 50, 0)
    vector = Vector("Vector", 100, 50, 0)

    # Simulate the battle between Gru and Vector.
    while not gru.is_dead() and not vector.is_dead():
        gru.attack(vector)
        vector.defend()

        if not vector.is_dead():
            vector.attack(gru)
            gru.defend()

    # Determine the winner and print the result.
    if gru.is_dead():
        print("Vector wins!")
    else:
        print("Gru wins!")
# Run the main function if this script is executed directly.
if __name__ == "__main__":
    main()
