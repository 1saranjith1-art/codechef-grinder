#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A, B, C be the amounts of money the three friends have.
 * The statements are:
 * A - B = x
 * B - C = y
 * C - A = z
 * 
 * Summing these equations:
 * (A - B) + (B - C) + (C - A) = x + y + z
 * 0 = x + y + z
 * 
 * We are given X = |x|, Y = |y|, Z = |z|.
 * The condition x + y + z = 0 implies that the sum of three signed values is 0.
 * This can be rewritten as:
 * x + y = -z  => |x + y| = |-z| = Z
 * Or more generally, one of the values must be the sum of the other two, 
 * or the sum of two must equal the third.
 * 
 * Possible combinations of signs for (x, y, z):
 * 1. x + y + z = 0 (e.g., x=1, y=1, z=-2) -> X + Y = Z
 * 2. x + y - z = 0 (e.g., x=1, y=2, z=3) -> X + Y = Z
 * 3. x - y + z = 0 (e.g., x=1, y=3, z=2) -> X + Z = Y
 * 4. -x + y + z = 0 (e.g., x=3, y=1, z=2) -> Y + Z = X
 * 
 * Essentially, the condition is satisfied if any one of the given values 
 * is equal to the sum of the other two, or if the sum of two values 
 * minus the third equals zero.
 * 
 * More simply:
 * x + y + z = 0
 * Given |x|=X, |y|=Y, |z|=Z, we need to check if there exist signs s1, s2, s3 in {-1, 1}
 * such that s1*X + s2*Y + s3*Z = 0.
 * This is equivalent to checking:
 * X + Y = Z OR X + Z = Y OR Y + Z = X OR X + Y + Z = 0 (not possible as X,Y,Z >= 1)
 * Actually, the condition is:
 * X + Y = Z OR X + Z = Y OR Y + Z = X OR X = Y + Z is not quite right.
 * The condition is: X = Y + Z or Y = X + Z or Z = X + Y is wrong.
 * It is: X + Y = Z or X + Z = Y or Y + Z = X is also wrong.
 * 
 * Correct logic:
 * x + y + z = 0
 * Possible scenarios:
 * x + y = z  => |x + y| = |z| = Z. Since x, y can be +/- X, +/- Y:
 * Possible: X+Y=Z, |X-Y|=Z.
 * This covers all cases: X+Y=Z, X=Y+Z, Y=X+Z.
 */

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // The condition x + y + z = 0 with |x|=X, |y|=Y, |z|=Z
    // means one of the following must hold:
    // X + Y = Z
    // X + Z = Y
    // Y + Z = X
    // Or more accurately, since we can choose signs:
    // X - Y - Z = 0 => X = Y + Z
    // -X + Y - Z = 0 => Y = X + Z
    // -X - Y + Z = 0 => Z = X + Y
    
    if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}