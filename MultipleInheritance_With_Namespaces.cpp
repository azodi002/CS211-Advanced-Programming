#include <iostream>
#include <string>


namespace ZooAnimals
{
	using namespace std;
	class Animal
	{
	private:
		string specie_name;
	public:
		Animal(string animal_type)
		{
			specie_name = animal_type;
		}
	
		Animal()
		{
			specie_name = "Unknown";
		}

		void toString()
		{
			cout << "Animal Type: " << specie_name << endl;	
		}

	};

	class AnimalSound:public Animal
	{
	private:
		string sound_type;
	public:
		AnimalSound():Animal(){};
	
		AnimalSound(string sounds_type, string animal_type):Animal(animal_type)
		{
			sound_type = sounds_type;
		}

		void toString()
		{
			Animal::toString();
			cout << "Animal's Sound Type: " << sound_type << endl;
		}
	};

	class specificAnimal:public AnimalSound, public Animal
	{
	private:
		string toy_name;
	public:
		specificAnimal():AnimalSound(){};

		specificAnimal(string toys_name, string sound_type, string animal_type):AnimalSound(sound_type,animal_type)
		{
			toy_name = toys_name;
		}

		void toString()
		{
			AnimalSound::toString();
			cout << "Animal's Toy Name: " << toy_name << endl;
		}
	};
	
}

int main(int argc, char* argv)
{
	{
	using namespace ZooAnimals;

	specificAnimal juniper("Bone", "High Woof", "German Sheppard Dog");
	juniper.toString();

	cout << "*************************" << endl;
	
	specificAnimal hunter("Yarn Ball", "Quiet Meow", "Garfield Cat");
	hunter.toString();
	
	getchar();


	}

	return 0;
}
