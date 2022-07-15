class MergeSort {

public:
	vector<int> arr;
	vector<int> temp;

	MergeSort(vector<int> tmp) {
		arr = tmp;
		temp.resize(arr.size());
		
	}
	void printArr() {
		for (auto &x : arr) {
			cout << x << " ";
		}
		cout << "\n";
	}
	void merge(int left, int mid, int right) {
		
		int i, j, k;
		i = left;
		j = mid;
		k = left;
		while (i <= mid - 1 && j <= right) {
			if (arr[i] <= arr[j]) {
				temp[k++] = arr[i++];
			}
			else {
				temp[k++] = arr[j++];
			}
		}

		while (i <= mid - 1) {
			temp[k++] = arr[i++];
		}

		while (j <= right) {
			temp[k++] = arr[j++];
		}
		for(i=left;i<=right;++i){
			arr[i] = temp[i];
		}
	}
	void merge_sort(int i, int j) {
		if (i < j) {
			int mid = i + (j - i) / 2;
			merge_sort(i, mid);
			merge_sort(mid + 1, j);
			merge(i, mid + 1, j);
		}
	}



};
