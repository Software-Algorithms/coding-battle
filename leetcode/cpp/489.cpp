/*
 * DFS, Design
 *
 */

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        dfs(0, 0, robot, 0);
    }

    void move2prev_pos(Robot &r) {
        r.turnLeft();
        r.turnLeft();
        r.move();
        r.turnRight();
        r.turnRight();
    }

    void dfs(int i, int j, Robot &robot, int d) {

        string t = to_string(i) + " " + to_string(j);

        if (v.count(t)) {
            return;
        }


        robot.clean();
        v.insert(t);


        for (int k = 0; k < 4 ; k++, d++) {
             d = d % 4;
            if (robot.move()) {
                dfs(i + dir[d][0], j + dir[d][1], robot, d);
                move2prev_pos(robot);
            }

            robot.turnRight();
        }

    }        

private:
    unordered_set<string> v;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

// Conclusion:
// 这一题如果只从dfs角度去检视，其实运用的算法不难。难点在于理解题目意图，这是一道机器人路径搜索任务结合的题目，
// 而这路径不是目标，而是扫寻所有区域，其实已经提示了用“穷举搜索”也就是DFS的方法，用一个记忆矩阵/集合来记录走过
// 的路径。
//
// 比较Tricky的一点是用string来表示路径：'i j'.




