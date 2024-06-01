
template <class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	found = false;
	location = -1;
	while (first <= last) {
		int mid = first + (last - first) / 2;

		if (a[mid] == key) {
			location = mid;
			found = true;
			return;
		}
		else if (a[mid] < key) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
}

template <class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	if (first > last) {
		found = false;
		location = -1;
		return;
	}
	
	int mid = first + (last - first) / 2;

	if (a[mid] == key) {
		location = mid;
		found = true;
		return;
	}
	else if (a[mid] < key){
		RecBinarySearch(a, mid + 1, last,key, found, location);
	}
	else {
		RecBinarySearch(a, first, mid -1,key, found, location);
	}
}