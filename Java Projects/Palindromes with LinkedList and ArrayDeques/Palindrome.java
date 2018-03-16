public class Palindrome {
    public Deque<Character> wordToDeque(String word) {
        Deque que = new LinkedListDeque();
        for (int i = 0; i < word.length(); i++) {
            que.addLast(word.charAt(i));
        }
        return que;
    }

    public boolean isPalindrome(String word) {
        if (word.length() == 0 || word.length() == 1) {
            return true;
        }
        Deque que = wordToDeque(word);
        Deque queBack = wordToDeque(word);
        for (int i = 0; i < que.size(); i++) {
            if (que.removeFirst() != queBack.removeLast()) {
                return false;
            }
        }
        return true;
    }

    public boolean isPalindrome(String word, CharacterComparator cc) {
        if (word.length() == 0 || word.length() == 1) {
            return true;
        }
        if (word.length() % 2 == 1) {
            String temp = word.substring(0, ((word.length() + 1) / 2) - 1)
                    + word.substring(((word.length() + 1) / 2));
            word = temp;
        }
        Deque que = wordToDeque(word);
        Deque queBack = wordToDeque(word);
        char a = 'a';
        char b = 'b';
        for (int i = 0; i < que.size(); i++) {
            a = (char) que.removeFirst();
            b = (char) queBack.removeLast();
            if (!cc.equalChars(a, b)) {
                return false;
            }
        }
        return true;
    }


}
