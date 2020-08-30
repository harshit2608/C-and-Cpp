import java.util.Scanner;

class Solution {
	public int mergeArrayCount(int arr[], int l, int m, int r) {
		int n1 = m - l + 1, n2 = r - m, ans = 0;
		int[] left = new int[n1];
		int[] right = new int[n2];
		for (int i = 0; i < n1; i++) {
			left[i] = arr[l + i];
		}
		for (int j = 0; j < n2; j++) {
			right[j] = arr[m + 1 + j];
		}
		int i = 0, j = 0, k = l;
		while (i < n1 && j < n2) {
			if (left[i] <= right[j]) {
				arr[k] = left[i];
				i++;
			} else {
				arr[k] = right[j];
				j++;
				ans = ans + (n1 - i);
			}
			k++;
		}
		while (i < n1) {
			arr[k++] = left[i++];
		}
		while (j < n2) {
			arr[k++] = right[j++];
		}
		return ans;
	}

	static void displayArray(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
	}

	public int mergeSortInv(int arr[], int l, int r) {
		int res = 0;
		if (l < r) {
			int m = l + (r - l) / 2;
			res += mergeSortInv(arr, l, m);
			res += mergeSortInv(arr, m + 1, r);
			res += mergeArrayCount(arr, l, m, r);
		}
		return res;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t;
		int n;
		int[] arr;
		t = sc.nextInt();
		while (t-- > 0) {
			n = sc.nextInt();
			arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			Solution sol = new Solution();
			int ans = sol.mergeSortInv(arr, 0, arr.length - 1);
			System.out.println(ans);
			System.out.println("Sorted");
			sol.displayArray(arr);
		}
		sc.close();
	}
}