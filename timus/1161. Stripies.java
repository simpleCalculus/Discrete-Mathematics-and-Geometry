import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
        }
        Arrays.sort(arr);
        double x = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            x = 2 * Math.sqrt(x * arr[i]);
        }
        System.out.println(String.format("%.2f", x));
    }
}
