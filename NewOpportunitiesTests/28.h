#pragma once
#include <vector>
#include <map>
#include <typeinfo>

namespace twenty_eighth {

	class Solution {
	public:
		std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
			std::multimap<double, std::vector<int>> closestPoints;

			auto calcDist = [](const std::vector<int>& point) {
				return sqrt(point[0] * point[0] + point[1] * point[1]);
			};

			double curDist = 0;
			for (const auto& point : points) {
				curDist = calcDist(point);
				if (closestPoints.size() < k) {
					closestPoints.insert({ curDist, point });
				}
				else {
					auto maxDistElem = --closestPoints.end();
					if (curDist > (*maxDistElem).first) {
						continue;
					}
					else {
						if (typeid(*maxDistElem) == typeid(std::pair<double, std::vector<int>>)) {
							closestPoints.erase(maxDistElem);
						}
						else {
							(*maxDistElem).second.pop_back();
						}
						closestPoints.insert({ curDist, point });
					}
				}
			}

			std::vector<std::vector<int>> result(k);
			int i = 0;
			for (auto& elem : closestPoints) {
				result[i++] = elem.second;
			}
			return result;

		}
	};

}