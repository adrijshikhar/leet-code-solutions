
/**
 * You are given a string that represents time in the format hh:mm. Some of the
 * digits are blank (represented by ?). Fill in ? such that the time represented
 * by this string is the maximum possible. Maximum time: 23:59, minimum time:
 * 00:00. You can assume that input string is always valid.
 * 
 * Example 1:
 * 
 * Input: "?4:5?" Output: "14:59" Example 2:
 * 
 * Input: "23:5?" Output: "23:59" Example 3:
 * 
 * Input: "2?:22" Output: "23:22" Example 4:
 * 
 * Input: "0?:??" Output: "09:59" Example 5:
 * 
 * Input: "??:??" Output: "23:59"
 */
public class MaximumTime {
  public static String maxTimeString(String time) {
    char[] ans = time.toCharArray();
    int c;
    if (ans[0] == '?') {
      c = Character.getNumericValue(ans[1]);
      if (3 < c)
        ans[0] = '1';
      else if (0 < c)
        ans[0] = '2';
      else {
        ans[0] = '2';
        ans[1] = '3';
      }
    }
    if (ans[1] == '?') {
      if ((ans[0] == '1' || ans[0] == '0'))
        ans[1] = '9';
      else if (ans[0] == '2')
        ans[1] = '3';
    }

    if (ans[3] == '?') {
      ans[3] = '5';
    }
    if (ans[4] == '?') {
      ans[4] = '9';
    }
    return new String(ans);

  }

  public static void main(String[] args) {
    String time = "?9:?9";
    System.out.println(time);

    String maxTime = maxTimeString(time);
    System.out.println(maxTime);
  }
}
