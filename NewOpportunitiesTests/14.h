#pragma once

namespace fourteenth {

    bool isBadVersion(int version) {
        if (version >= 1702766719)
            return true;
        else
            return false;
    }

    class Solution {
    public:
        int firstBadVersion(int n) {
            if (isBadVersion(1))
                return 1;
            int lastValid = 1;
            int firstInvalid = n;
            long long int mid = (firstInvalid - lastValid) / 2;

            while (firstInvalid - lastValid > 1) {
                if (!isBadVersion(mid))
                    lastValid = mid;
                else
                    firstInvalid = mid;
                mid = lastValid + (firstInvalid - lastValid) / 2;
            }
            return firstInvalid;
        }
    };

}