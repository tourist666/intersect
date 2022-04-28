vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		return intersect(nums2, nums1);
	}
	unordered_map <int, int> m;
	for (int num : nums1) {  //这里的for结构是用来遍历nums1中的所有数据
		m[num]++;  //将每个数对应的下标均初始化为1
	}
	vector<int> intersection;
	for (int num : nums2) {
		if (m.count(num)) {  //m.count（key）判断key是否在m中，存在返回1，不存在返回0
			intersection.push_back(num);
			--m[num];
			if (m[num] == 0) {
				m.erase(num); //擦除数据
			}
		}
	}
	return intersection;
}
