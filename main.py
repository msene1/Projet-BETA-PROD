from car import Car
from motorcycle import Motorcycle
from bus import Bus
from electric_scooter import ElectricScooter
from bicycle import Bicycle

vehicles = []

# ...

def add_vehicle():
    vehicle_type = input("Entrer le type de véhicule (1-Voiture, 2- Moto, 3-Bus, 4-Trotinette, 5-Vélo): ")
    brand = input("Enter marque: ")
    model = input("Enter model: ")
    year = input("Enter année: ")
    color = input("Enter couleur: ")
    num_vignette_critair = input("Entrer numéro vignette Crit'Air : ")
    license_plate = input("Entrer plaque d'immatriculation: ")

    if vehicle_type == "1":
        vehicle = Car(brand, model, year, color, num_vignette_critair, license_plate)
    elif vehicle_type == "2":
        vehicle = Motorcycle(brand, model, year, color, num_vignette_critair, license_plate)
    elif vehicle_type == "3":
        vehicle = Bus(brand, model, year, color, num_vignette_critair, license_plate)
    elif vehicle_type == "4 scooter":
        vehicle = ElectricScooter(brand, model, year, color, num_vignette_critair, license_plate)
    elif vehicle_type == "5":
        vehicle = Bicycle(brand, model, year, color, num_vignette_critair, license_plate)
    else:
        print("Invalid vehicle type.")
        return

    vehicles.append(vehicle)
    print("Vehicle ajouter avec succès.")

# ...


def remove_vehicle():
    license_plate = input("Entrer la plaque d'immatriculation du véhicule à supprimer: ")
    for vehicle in vehicles:
        if vehicle.get_license_plate() == license_plate:
            vehicles.remove(vehicle)
            print("Vehicle supprimer avec succès.")
            return
    print("Vehicle not found.")

def modify_vehicle():
    license_plate = input("Entrer la plaque d'immatriculation du véhicule à modifier: ")
    for vehicle in vehicles:
        if vehicle.get_license_plate() == license_plate:
            print("Modify Vehicle:")
            brand = input(f"Enter marque ({vehicle.get_brand()}): ") or vehicle.get_brand()
            model = input(f"Enter modele ({vehicle.get_model()}): ") or vehicle.get_model()
            year = input(f"Enter année ({vehicle.get_year()}): ") or vehicle.get_year()
            color = input(f"Enter couleur ({vehicle.get_color()}): ") or vehicle.get_color()
            num_vignette_critair = input(f"Entrer vignette Crit'Air ({vehicle.get_num_vignette_critair()}): ") or vehicle.get_num_vignette_critair()
            license_plate = input(f"Entrer plaque d'immatriculation ({vehicle.get_license_plate()}): ") or vehicle.get_license_plate()
            vehicle.brand = brand
            vehicle.model = model
            vehicle.year = year
            vehicle.color = color
            vehicle.num_vignette_critair = num_vignette_critair
            vehicle.license_plate = license_plate
            print("Vehicle modifier avec succès.")
            return
    print("Vehicle not found.")

def display_statistics():
    print("Statistics:")
    print("1. Véhicule Type")
    print("2. Couleur")
    print("3. Vignette Crit'Air")
    print("4. Marque")
    print("5. Plaque d'immatriculation")

    choice = input("Enter your choice: ")

    if choice == "1":
        vehicle_type_statistics()
    elif choice == "2":
        color_statistics()
    elif choice == "3":
        vignette_statistics()
    elif choice == "4":
        brand_statistics()
    elif choice == "5":
        license_plate_statistics()
    else:
        print("Invalid choice.")

def vehicle_type_statistics():
    vehicle_types = {}
    for vehicle in vehicles:
        vehicle_type = type(vehicle).__name__
        if vehicle_type in vehicle_types:
            vehicle_types[vehicle_type] += 1
        else:
            vehicle_types[vehicle_type] = 1

    print("Vehicle Type Statistics:")
    for vehicle_type, count in vehicle_types.items():
        print(f"{vehicle_type}: {count}")

def color_statistics():
    colors = {}
    for vehicle in vehicles:
        color = vehicle.get_color()
        if color in colors:
            colors[color] += 1
        else:
            colors[color] = 1

    print("Color Statistics:")
    for color, count in colors.items():
        print(f"{color}: {count}")

def vignette_statistics():
    vignettes = {}
    for vehicle in vehicles:
        vignette = vehicle.get_num_vignette_critair()
        if vignette in vignettes:
            vignettes[vignette] += 1
        else:
            vignettes[vignette] = 1

    print("Crit'Air Vignette Statistics:")
    for vignette, count in vignettes.items():
        print(f"Vignette {vignette}: {count}")

def brand_statistics():
    brands = {}
    for vehicle in vehicles:
        brand = vehicle.get_brand()
        if brand in brands:
            brands[brand] += 1
        else:
            brands[brand] = 1

    print("Brand Statistics:")
    for brand, count in brands.items():
        print(f"{brand}: {count}")

def license_plate_statistics():
    license_plates = {}
    for vehicle in vehicles:
        license_plate = vehicle.get_license_plate()
        if license_plate in license_plates:
            license_plates[license_plate] += 1
        else:
            license_plates[license_plate] = 1

    print("License Plate Statistics:")
    for license_plate, count in license_plates.items():
        print(f"{license_plate}: {count}")

def display_menu():
    print("==== Vehicle Management System ====")
    print("1. Add Vehicle")
    print("2. Remove Vehicle")
    print("3. Modify Vehicle")
    print("4. Display Statistics")
    print("5. Display Vehicles") 
    print("6. Quit")

def main():
    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            add_vehicle()
        elif choice == "2":
            remove_vehicle()
        elif choice == "3":
            modify_vehicle()
        elif choice == "4":
            display_statistics()
        elif choice == "5":
            display_vehicles()  
        elif choice == "6":
            print("Quitting the program...")
            break
        else:
            print("Invalid choice. Please try again.")



def display_vehicles():
    print("List of Vehicles:")
    for vehicle in vehicles:
        print(f"Vehicle Type: {type(vehicle).__name__}")
        print(f"Brand: {vehicle.get_brand()}")
        print(f"Model: {vehicle.get_model()}")
        print(f"Year: {vehicle.get_year()}")
        print(f"Color: {vehicle.get_color()}")
        print(f"Crit'Air Vignette: {vehicle.get_num_vignette_critair()}")
        print(f"License Plate: {vehicle.get_license_plate()}")
        print("--------------------")


def main():
    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            add_vehicle()
        elif choice == "2":
            remove_vehicle()
        elif choice == "3":
            modify_vehicle()
        elif choice == "4":
            display_statistics()
        elif choice == "5":
            display_vehicles()
        elif choice == "6":
            print("Quitting the program...")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()