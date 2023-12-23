// A little hardcoded because I was in a hurry, but it works!

/** because "dashing" implies speed */
type Dasher = "💨";

/** representing dancing or grace */
type Dancer = "💃";

/** a deer, prancing */
type Prancer = "🦌";

/** a star for the dazzling, slightly mischievous Vixen */
type Vixen = "🌟";

/** for the celestial body that shares its name */
type Comet = "☄️";

/** symbolizing love, as Cupid is the god of love */
type Cupid = "❤️";

/** representing thunder, as "Donner" means thunder in German */
type Donner = "🌩️";

/** meaning lightning in German, hence the lightning bolt */
type Blitzen = "⚡";

/** for his famous red nose */
type Rudolph = "🔴";

type Reindeer = Dasher | Dancer | Prancer | Vixen | Comet | Cupid | Donner | Blitzen | Rudolph;

type SudokuThree = [Reindeer, Reindeer, Reindeer];
type SudokuRow = [SudokuThree, SudokuThree, SudokuThree];
type SudokuGroup = [SudokuRow, SudokuRow, SudokuRow];
type Sudoku = [...SudokuGroup, ...SudokuGroup, ...SudokuGroup];
type LooseSudoku = Reindeer[][][];

type GetColumn<Board extends any[][], Idx extends number> = Board extends []
	? []
	: Board extends [infer First extends any[], ...infer Rest extends any[][]]
		? [First[Idx], ...GetColumn<Rest, Idx>]
		: never;

type Transpose<
	Board extends Reindeer[][],
	Cur extends Reindeer[][] = [],
> = Cur["length"] extends Board["length"]
	? Cur
	: Transpose<Board, [...Cur, GetColumn<Board, Cur["length"]>]>;

type FlattenRow<Row extends any[][]> = Row extends [
	infer First extends any[],
	...infer Rest extends any[][],
]
	? [...First, ...FlattenRow<Rest>]
	: Row["length"] extends 1
		? Row[0]
		: [];

type FlattenEach<Board extends LooseSudoku> = Board extends [
	infer First extends LooseSudoku[number],
	...infer Rest extends LooseSudoku,
]
	? [FlattenRow<First>, ...FlattenEach<Rest>]
	: [];

type OmitUnion<A, B> = [A] extends [B | infer Rest] ? Rest : never;

type HasEveryRow<T extends Reindeer[], Reqs extends Reindeer = Reindeer> = T extends [
	infer First,
	...infer Rest extends Reindeer[],
]
	? First extends Reqs
		? HasEveryRow<Rest, OmitUnion<Reqs, First> extends Reindeer ? OmitUnion<Reqs, First> : never>
		: false
	: true;

type Ex2 = HasEveryRow<['💃', '🦌', '💨', '❤️', '🌟', '☄️', '⚡', '🔴', '🌟']>

type HasEvery<T extends Reindeer[][]> = T extends [
	infer First extends Reindeer[],
	...infer Rest extends Reindeer[][],
]
	? HasEveryRow<First> extends true
		? HasEvery<Rest>
		: false
	: true;

type Groups<T extends Sudoku> = [[T[0], T[1], T[2]], [T[3], T[4], T[5]], [T[6], T[7], T[8]]];

type RegionsGroup<T extends SudokuGroup> = [
	[...T[0][0], ...T[1][0], ...T[2][0]],
	[...T[0][1], ...T[1][1], ...T[2][1]],
	[...T[0][2], ...T[1][2], ...T[2][2]],
];

type Regions<T extends SudokuGroup[]> = T extends [
	infer First extends SudokuGroup,
	...infer Rest extends SudokuGroup[],
]
	? [...RegionsGroup<First>, ...Regions<Rest>]
	: [];

type Validate<T extends Sudoku> = [
	HasEvery<FlattenEach<T>> & HasEvery<Transpose<FlattenEach<T>>> & HasEvery<Regions<Groups<T>>>,
] extends [never | false]
	? false
	: true;

type exe = [true & false] extends [never] ? true : false;
