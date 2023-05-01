//#include "InstanceManager.h"
//
//template<typename T>
//static T InstanceManager<T>::get(std::string id)
//{
//	if (this->_idToIndexMap.contains(id)) {
//		return this->_instances[this->_idToIndexMap[id]];
//	}
//	return NULL;
//};
//
//template<typename T>
//static std::string InstanceManager<T>::getNextID(){
//	return strcat(typeid(T).name(), to_string(int(this->_instances.size()))));
//}
//
//template<typename T>
//static void InstanceManager<T>::add(T instance)
//{
//	std::string id = this->getNextId();
//	this->_idToIndexMap[id] = int(this->_instances.size());
//	this->_instances.push_back(instance);
//};
//
//template<typename T>
//static void InstanceManager<T>::update(std::string id, T instance)
//{
//	if (this->_idToIndexMap.contains(id)) {
//		this->_instances[this->_idToIndexMap[id]] = instance;
//	}
//	else {
//		throw std::invalid_argument("Error: could not update instance with id. Reason: id not found.");
//	}
//};
//
//template<typename T>
//static void InstanceManager<T>::deletee(std::string id)
//{
//	if (this->_idToIndexMap.contains(id)) {
//		this->_instances.erase(this->_instances.begin() + this->_idToIndexMap[id]);
//		this->_idToIndexMap.erase(id);
//	}
//	else {
//		throw std::invalid_argument("Error: could not delete instance with id. Reason: id not found.");
//	}
//};