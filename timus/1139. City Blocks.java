import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m;
        int ans = 0;
        n = in.nextInt();
        m = in.nextInt();
        int i = 0;
        int j = 0;
        while (true) {
            ++ans;
            //part1 from j - 1 to j at i
            if ((j * (n - 1) < (m - 1) * (i + 1)) &&
                    (m - 1) * (i + 1) < (j + 1) * (n - 1)) {
                i++;
            } else if ((i * (m - 1) < (j + 1) * (n - 1)) &&
                    ((j + 1) * (n - 1) < (i + 1) * (m - 1))) {
                j++;
            } else {
                i++;
                j++;
            }
            if (i == n - 1 && j == m - 1) {
                break;
            }
        }
        System.out.println(ans);
    }
}
