#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

template <typename T>
class InstanceManager
{
public:
	inline static std::map<std::string, int> _idToIndexMap;
	inline static std::vector<T> _instances;
	static T get(std::string id)
	{
		if (InstanceManager<T>::_idToIndexMap.contains(id)) {
			return InstanceManager<T>::_instances[InstanceManager<T>::_idToIndexMap[id]];
		}
		return NULL;
	};
	static T getByIndex(int index)
	{
		return InstanceManager<T>::_instances[index];
	};
	static std::string getNextID() {
		return typeid(T).name() + std::to_string(int(InstanceManager<T>::_instances.size()));
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

};

