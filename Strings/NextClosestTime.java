import java.util.*;

class Solution {
  public String nextClosestTime(String time) {
    int minutes = Integer.parseInt(time.substring(0, 2)) * 60;
    minutes += Integer.parseInt(time.substring(3));

    HashSet<Integer> digits = new HashSet<>();

    for (char c : time.toCharArray())
      digits.add(c - '0');

    while (true) {
      minutes = (minutes + 1) % (24 * 60);
      int[] nextTime = new int[] { minutes / 60 / 10, minutes / 60 % 10, minutes % 60 / 10, minutes % 60 % 10 };
      boolean isValid = true;
      for (int i : nextTime) {
        if (!digits.contains(i))
          isValid = false;
      }
      if (isValid)
        return String.format("%02d:%02d", minutes / 60, minutes % 60);
    }
  }
}

public class NextClosestTime {

  public static void main(final String[] args) {
    final Solution s = new Solution();
    String a = s.nextClosestTime("19:34");
    System.out.println(a);

  }
}
