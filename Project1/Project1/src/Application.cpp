#include <iostream>
#include <map> // sorted : red-black tree
#include <unordered_map> // unordered map : hash table, usually faster than map
// If you want to constantly retreive specific element from
// vector could be problem. - have to search entire vector

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;

	// less than operator is responsible for more than sorting
	// it is also responsible for finding the element
	bool operator<(const CityRecord& other) const
	{
		return Population < other.Population;
	}
};

namespace std{
	template<>
	struct hash<CityRecord> {
		size_t operator()(const CityRecord& city) const
		{
			// return any kind of hash value we want
			// std already has hash function for string
			return hash<std::string>()(city.Name);
		}
	};
}

int main() 
{
	// use unordered map wherever possible, if you don't need to sort

	//  If you have a pre-constructed object that you want to add to the vector,
	// push_back() is the appropriate choice. 
	// If you want to construct a new object in-place within the vector,
	// emplace_back() is the better choice.

	/*
	std::vector<CityRecord> cities;
	
	// needs constructor for CityRecord
	cities.emplace_back("Melbourne", 4000000, -37.8136, 144.9631);
	cities.emplace_back("Sydney", 5000000, -33.8651, 151.2099);
	cities.emplace_back("Brisbane", 2000000, -27.4698, 153.0251);
	cities.emplace_back("Perth", 2000000, -31.9505, 115.8605);
	cities.emplace_back("Adelaide", 1000000, -34.9285, 138.6007);
	
	for (const auto& city : cities)
	{
		if (city.Name == "Melbourne")
		{
			city.Population;
			break;
		}
	}
	*/
	
	// map : sorted
	// api is same, change it to unordered map if needed
	std::map<std::string, CityRecord> cityMap;
	cityMap["Melobourne"] = CityRecord { "Melbourne", 4000000, -37.8136, 144.9631 };
	cityMap["Sydney"] = CityRecord{ "Sydney", 5000000, -33.8651, 151.2099 };
	cityMap["Brisbane"] = CityRecord{ "Brisbane", 2000000, -27.4698, 153.0251 };
	cityMap["Perth"] = CityRecord{ "Perth", 2000000, -31.9505, 115.8605 };
	cityMap["Adelaide"] = CityRecord{ "Adelaide", 1000000, -34.9285, 138.6007 };

	// if Melbourne data doesn't exist in map/unorderd_map, it will create one (without copying)
	CityRecord& melbourne = cityMap["Melbourne"]; 
	melbourne.Population;

	// copying
	CityRecord melbourneData;
	melbourneData.Name = "Melobourne";
	melbourneData.Population = 4000000;
	cityMap["Melbourne"] = melbourneData;

	// if you just want to retrieve data, use at
	// there is no const verison of [] operator
	const auto& cities = cityMap;
	CityRecord& melbourne = cityMap.at("Melobourne");

	if (cityMap.find("Melbourne") != cityMap.end())
	{
		// found
		const CityRecord& melbourne2 = cities.at("Melobourne");
	}

	std::unordered_map<CityRecord, uint32_t> foundedMap; // error 
	// will trying to use hash function to hash CityRecord
	// need to provide hash function for CityRecord -> google it

	// other data rather than string is whatever 
	foundedMap[CityRecord{ "Melbourne", 4000000, -37.8136, 144.9631 }] = 1835;
	uint32_t melbourneFounded = foundedMap[CityRecord{ "Melbourne", 4000000, -37.8136, 144.9631 }];
	
	// iterate through map is slower than vector, however its useful to iterate through map
	// using c++17 struct binding
	for (const auto& [city, year] : foundedMap)
	{
		// city is key, year is value
	}

	// how to delete element
	cityMap.erase("Melbourne");
	 
	// need to provide comparator for CityRecord in ordered map
	std::map<CityRecord, uint32_t> cityFounded;
	cityFounded[{ "Melbourne", 4000000, -37.8136, 144.9631 }] = 1835;
	
	std::cin.get(); 
}