import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int num = scn.nextInt();
        scn.nextLine();

        while (num-- > 0) {
            scn.nextLine();
            String u = scn.nextLine();
            String v = scn.nextLine();

            HashMap<Character, ArrayList<Character>> map = new HashMap<>();
            HashMap<Character, Integer> in = new HashMap<>();
            HashMap<Character, Boolean> visited = new HashMap<>();
            int n = 0;

            for (int i = 0; i < u.length(); i++) {
                if (u.charAt(i) == ' ') continue;
                char c = u.charAt(i);
                map.put(c, new ArrayList<>());
                in.put(c, 0);
                visited.put(c, false);
                n++;
            }

            for (int i = 0; i < v.length(); i += 4) {
                char c1 = v.charAt(i);
                char c2 = v.charAt(i + 2);

                map.get(c1).add(c2);
                in.put(c2, in.get(c2) + 1);
            }

            StringBuilder curr = new StringBuilder();
            ArrayList<String> ans = new ArrayList<>();
            backtrack(curr, ans, map, in, visited, n);

            Collections.sort(ans);
            if (ans.isEmpty()) {
                System.out.println("NO");
            } else {
                for (String s : ans) {
                    for (int i = 0; i < s.length(); i++) {
                        if (i > 0) System.out.print(" ");
                        System.out.print(s.charAt(i));
                    }
                    System.out.println();
                }
            }

            if (num > 0) System.out.println();
        }
    }

    static void backtrack(StringBuilder curr, ArrayList<String> ans, HashMap<Character, ArrayList<Character>> map, HashMap<Character, Integer> in, HashMap<Character, Boolean> visited, int n) {
        if (curr.length() == n) {
            ans.add(curr.toString());
            return;
        }

            List<Character> keys = new ArrayList<>(map.keySet());
            Collections.sort(keys);
            for (char c : keys) {
            if (!visited.get(c) && in.get(c) == 0) {
                curr.append(c);
                visited.put(c, true);

                for (char neighbor : map.get(c)) {
                    in.put(neighbor, in.get(neighbor) - 1);
                }

                backtrack(curr, ans, map, in, visited, n);

                curr.deleteCharAt(curr.length() - 1);
                visited.put(c, false);

                for (char neighbor : map.get(c)) {
                    in.put(neighbor, in.get(neighbor) + 1);
                }
            }
        }
    }
}