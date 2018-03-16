public class OffByN implements CharacterComparator {
    private int offBy;

    public OffByN(int N) {
        offBy = N;
    }

    @Override
    public boolean equalChars(char x, char y) {
        if (Math.abs(x - y) == offBy) {
            return true;
        }
        return false;
    }
}
