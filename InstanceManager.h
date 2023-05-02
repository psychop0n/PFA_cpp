#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <iostream>

template <typename T>
class InstanceManager
{
public:
	inline static std::map<std::string, int> _idToIndexMap;
	inline static std::vector<T> _instances;
	
	static T get(std::string id)
	{
		return InstanceManager<T>::_instances[InstanceManager<T>::_idToIndexMap[id]];
	};
	static T getByIndex(int index)
	{
		return InstanceManager<T>::_instances[index];
	};
	static std::string getNextID() {
		return std::to_string(int(InstanceManager<T>::_instances.size()));
	}
	static void add(T instance)
	{
		std::string id = InstanceManager<T>::getNextID();
		InstanceManager<T>::_idToIndexMap[id] = int(InstanceManager<T>::_instances.size());
		InstanceManager<T>::_instances.push_back(instance);
	};
	static void update(std::string id, T instance)
	{
		if (InstanceManager<T>::_idToIndexMap.contains(id)) {
			InstanceManager<T>::_instances[InstanceManager<T>::_idToIndexMap[id]] = instance;
		}
		else {
			throw std::invalid_argument("Error: could not update instance with id. Reason: id not found.");
		}
	};
	static void deletee(std::string id)
	{
		if (InstanceManager<T>::_idToIndexMap.contains(id)) {
			InstanceManager<T>::_instances.erase(InstanceManager<T>::_instances.begin() + InstanceManager<T>::_idToIndexMap[id]);
			InstanceManager<T>::_idToIndexMap.erase(id);
		}
		else {
			throw std::invalid_argument("Error: could not delete instance with id. Reason: id not found.");
		}
	};
	
	static void addInstanceFromInput() {
		T instance{};
		std::cin >> instance;
		InstanceManager<T>::add(instance);
	}
	static void editInstanceFromInput() {
		std::string id;
		InstanceManager<T>::printAll();

		std::cout << "Saisir l'ID du " << typeid(T).name() << " a modifier: ";
		std::cin >> id;

		T instance = InstanceManager<T>::get(id);
		std::cin >> instance;
		InstanceManager<T>::update(id, instance);
	}
	static void deleteInstanceFromInput() {
		std::string id;
		InstanceManager<T>::printAll();

		std::cout << "Saisir l'ID du " << typeid(T).name() << " a modifier: ";
		std::cin >> id;

		InstanceManager<T>::deletee(id);
	}
	static void printAll() {
		for (int i = 0; i < InstanceManager<T>::_instances.size(); i++) {
			std::cout << InstanceManager<T>::_instances[i] << std::endl;
		}
	};

	static char displayMenu() {
		char choice;
		std::cout << "[1] - Ajouter un " << typeid(T).name() << std::endl;
		std::cout << "[2] - Modifier un " << typeid(T).name() << std::endl;
		std::cout << "[3] - Supprimer un " << typeid(T).name() << std::endl;
		std::cout << "[4] - Lister les " << typeid(T).name() << std::endl;
		std::cout << "[5] - Retour" << std::endl;
		std::cin >> choice;
		return choice;
	}

	static void manageMenu() {
		char choice;
		while ((choice = InstanceManager<T>::displayMenu()) != '5') {
			switch (choice) {
			case '1':
				// Call the function to add a client
				InstanceManager<T>::addInstanceFromInput();
				break;
			case '2':
				// Call the function to edit a client
				InstanceManager<T>::editInstanceFromInput();
				break;
			case '3':
				// Call the function to delete a client
				InstanceManager<T>::deleteInstanceFromInput();
				break;
			case '4':
				// Call the function to list all clients
				InstanceManager<T>::printAll();
				break;
			default:
				std::cout << "Choix invalide" << std::endl;
			}
		}
	}
};
