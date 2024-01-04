import { Expect, Equal } from "type-testing";

type Alley = "  ";
type Person = "🎅";
type Tree = "🎄";
type MazeItem = Tree | Person | Alley;
type DELICIOUS_COOKIES = "🍪";
type MazeMatrix = MazeItem[][];
type Directions = "up" | "down" | "left" | "right";

type GetPosition<Maze extends MazeMatrix, RowNum extends 0[] = [], ColNum extends 0[] = []> =
	Maze extends [infer Row extends MazeMatrix[number], ...infer Rest extends MazeMatrix]
		? Person extends Row[number]
      ? Row extends [infer Char extends MazeItem, ...infer RestIn extends MazeMatrix[number]]
        ? Char extends Person
          ? [RowNum['length'], ColNum['length']]
          : GetPosition<[RestIn, ...Rest], RowNum, [...ColNum, 0]>
        : GetPosition<Rest, [...RowNum, 0], []>
      : GetPosition<Rest, [...RowNum, 0], []>
		: [-1, -1]

type dx = {
	'up': 0,
	'down': 0,
	'left': -1,
	'right': 1
}

type dy = {
	up: -1,
	down: 1,
	left: 0,
	right: 0
}

type Decrement = {
  0: -1,
  1: 0,
  2: 1,
  3: 2,
  4: 3,
  5: 4,
  6: 5,
  7: 6,
  8: 7,
  9: 8,
}

type Increment = {
  0: 1,
  1: 2,
  2: 3,
  3: 4,
  4: 5,
  5: 6,
  6: 7,
  7: 8,
  8: 9,
  9: 10,
}

type AddOne<N extends number, A extends number> =
	A extends -1
		? Decrement[N extends keyof Decrement ? N : never]
		: A extends 1
			? Increment[N extends keyof Increment ? N : never]
			: N

type Replace<Maze extends MazeMatrix, X extends number, Y extends number, NewThing = MazeItem, CurRow extends 0[] = [], CurColumn extends 0[] = []> =
  Maze extends [infer Row extends MazeMatrix[number], ...infer Rest extends MazeMatrix]
    ? CurRow['length'] extends X
      ? Row extends [infer Char, ...infer Rest2 extends MazeMatrix[number]]
        ? CurColumn['length'] extends Y
          ? [[NewThing, ...Rest2], ...Rest]
          : (Replace<[Rest2], X, Y, NewThing, CurRow, [0, ...CurColumn]>)[0] extends infer RestRow1 extends MazeMatrix[number] ? [[Char, ...RestRow1], ...Rest] : never
        : []
      : [Row, ...Replace<Rest, X, Y, NewThing, [...CurRow, 0], []>]
    : []

type Move<CurrentMaze extends MazeMatrix, Direction extends Directions> =
	GetPosition<CurrentMaze> extends [infer X extends number, infer Y extends number]
		? [AddOne<X, dy[Direction]>, AddOne<Y, dx[Direction]>] extends [infer X2 extends number, infer Y2 extends number]
			? X2 extends -1 | 10
        ? WinPhase
        : Y2 extends -1 | 10
          ? WinPhase
          // : [X2, Y2]
          : CurrentMaze[X2][Y2] extends Alley
						? Replace<CurrentMaze, X2, Y2, Person> extends infer PersonMove extends MazeMatrix
							? Replace<PersonMove, X, Y, Alley>
							: never
						: CurrentMaze
			: never
		: never;

type BuildArray<El extends any, Mx extends number, Cur extends El[] = []> =
	Mx extends Cur['length']
		? Cur
		: BuildArray<El, Mx, [...Cur, El]>

type WinPhase = BuildArray<BuildArray<DELICIOUS_COOKIES, 10>, 10>
