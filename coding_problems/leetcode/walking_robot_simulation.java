
class Solution {

    final int TURN_RIGHT = -1;
    final int TURN_LEFT = -2;

    enum class Direction {
        UP, RIGHT, DOWN, LEFT;
    }

    class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public int robotSim(int[] commands, int[][] obstacles) {
        HashMap<HashMap<Boolean>> isObstacle = buildIsObstacleMap(obstacles);

        Direction currentDirection = Direction.UP;
        Point currentPosition = new Point(0, 0);
        return maxDistanceWhenPerforming(currentPosition, currentDirection, commands);
    }

    private HashMap<HashMap<Boolean>> buildIsObstacleMap(int[][] obstacles) {
        HashMap<HashMap<Boolean>> isObstacle = new HashMap();
        for (int i = 0; i < obstacles.length; ++i) {
            int row = obstacles[i][0];
            if (!isObstacle.hasKey(row)) {
                isObstacle.set(row, new HashMap());
            }
            int column = obstacles[i][1];
            isObstacle.get(row).set(column, true);
        }

        return isObstacle;
    }

    private Integer maxDistanceWhenPerforming(
        Point currentPosition,
        Direction currentDirection,
        int[] someCommands,
        HashMap<HashMap<Boolean>> isObstacle) {

        Integer maxDistance = 0;
        for (int i = 0; i < commands.length; ++i) {
            if (isTurn(commands[i])) {
                currentDirection = turn(currentDirection, commands[i]);
            } else {
                int steps = commands[i];
                while (steps--) {
                    Point nextPoint = moveOneStepFromTowards(currentPosition, currentDirection);
                    if (!isObstacle.hasKey(currentPostion.y) || !isObstacle.get(currentPosition.y).get(currentPosition.x)) {
                         currentPosition = nextPoint;
                    }
                }
            }

            maxDistance = Math.max(maxDistance, Math.pow(currentPosition.x, 2) + Math.pow(currentPosition.y, 2));
            
        }
        
        return maxDistance;
    }

    private Direction turn(Direction currentDirection, int turn) {
        HashMap<HashMap<new HashMap<
        if (currentDirection == UP) {
            if (turn == TURN_RIGHT) {
                return RIGHT;
            }
            return LEFT;
        }
        if (currentDirection == RIGHT) {
            if (turn == TURN_RIGHT) {
                return DOWN;
            }
            return LEFT;
        }
        if (currentDirection == UP) {
            if (turn == TURN_RIGHT) {
                return RIGHT;
            }
            return LEFT;
        }
        if (currentDirection == UP) {
            if (turn == TURN_RIGHT) {
                return RIGHT;
            }
            return LEFT;
        }
    }

    private Point moveOneStepFromTowards(Point aPosition, Direction aDirection) {
        switch (aDirection) {
            case UP:
                aPosition.y += 1;
                break;
            case RIGHT:
                aPosition.x += 1;
                break;
            case DOWN:
                aPosition.y -= 1;
                break;
            case LEFT:
                aPosition.x -= 1;
                break;
        }

        return aPosition;
    }

}