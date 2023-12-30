type Connect4Chips = "🔴" | "🟡";
type Connect4Cell = Connect4Chips | "  ";
type Connect4State = "🔴" | "🟡" | "🔴 Won" | "🟡 Won" | "Draw";

type EmptyBoard = [
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
	["  ", "  ", "  ", "  ", "  ", "  ", "  "],
];

type GameState = {
	board: Connect4Cell[][];
	state: Connect4State;
};

type CheckRow<Row extends GameState["board"][number]> = Row extends [
	"🟡",
	"🟡",
	"🟡",
	"🟡",
	...infer Rest,
]
	? "🟡"
	: Row extends ["🔴", "🔴", "🔴", "🔴", ...infer Rest]
		? "🔴"
		: Row extends [infer First, ...infer Rest extends GameState["board"][number]]
			? CheckRow<Rest>
			: false;

type Decrement<N extends number, Cur extends 0[] = []> = [...Cur, 0]["length"] extends N
	? Cur["length"]
	: Decrement<N, [...Cur, 0]>;

type GetDiagonal<
	Board extends GameState["board"],
	Idx extends number & keyof Board[0],
> = Idx extends 0
	? [Board[0][0]]
	: Board extends [infer First, ...infer Rest extends GameState["board"]]
		? [...GetDiagonal<Rest, Decrement<Idx>>, Board[0][Idx]]
		: [];

type CheckDagWin<Board extends GameState['board'], Cur extends 0[] = []> =
  Cur['length'] extends Board[0]['length']
    ? false
    : CheckRow<GetDiagonal<Board, Cur['length']>> extends false
      ? CheckDagWin<Board, [...Cur, 0]>
      : CheckRow<GetDiagonal<Board, Cur['length']>>

type CheckWin<Board extends GameState["board"]> = Board extends [
	infer Row extends GameState["board"][number],
	...infer Rest extends GameState["board"],
]
	? CheckRow<Row> extends Connect4Chips
		? CheckRow<Row>
		: CheckWin<Rest>
	: false;

type CheckWinOverall<Board extends GameState['board']> =
  CheckWin<Board> extends false
    ? CheckDagWin<Board>
    : CheckWin<Board>

type OmitUnion<A, B> = [A] extends [B | infer Rest] ? Rest : never;

type CheckState<Game extends GameState> = CheckWinOverall<Game["board"]> extends false
	? "  " extends Game["board"][number][number]
		? OmitUnion<Connect4Chips, Game["state"]>
		: "Draw"
	: `${CheckWinOverall<Game["board"]>} Won`;

type ShiftIt<Row extends GameState["board"][number], Piece extends Connect4Chips> = Row extends [
	"  ",
	...infer Rest extends Connect4Cell[],
]
	? Rest extends ["  ", ...infer Rest2]
		? ["  ", ...ShiftIt<Rest, Piece>]
		: [Piece, ...Rest]
	: Row extends ["  "]
		? [Piece]
		: Row;

type test_move1_actual2 = ShiftIt<["  ", "  "], "🟡">;

type RunItTarget<
	Board extends GameState["board"],
	Target extends number,
	Args extends Connect4Chips,
	Cur extends 0[] = [],
> = Board extends [
	infer First extends GameState["board"][number],
	...infer Rest extends GameState["board"],
]
	? Target extends Cur["length"]
		? [ShiftIt<First, Args>, ...Rest]
		: [First, ...RunItTarget<Rest, Target, Args, [...Cur, 0]>]
	: never;

type RunIt<
	Board extends GameState["board"],
	Col extends number,
	Piece extends Connect4Chips,
> = Transpose<Board> extends infer Transposed extends GameState["board"]
	? Col extends keyof Transposed
		? Transpose<RunItTarget<Transposed, Col, Piece>>
		: never
	: never;

type GetColumn<Board extends any[][], Idx extends number> = Board extends []
	? []
	: Board extends [infer First extends any[], ...infer Rest extends any[][]]
		? [First[Idx], ...GetColumn<Rest, Idx>]
		: never;

type Transpose<
	Board extends Connect4Cell[][],
	Cur extends Connect4Cell[][] = [],
> = Cur["length"] extends Board[0]["length"]
	? Cur
	: Transpose<Board, [...Cur, GetColumn<Board, Cur["length"]>]>;

type NewGame = {
	board: EmptyBoard;
	state: "🟡";
};

type Connect4<Game extends GameState, Place extends number> = RunIt<
	Game["board"],
	Place,
	Game["state"] extends Connect4Chips ? Game["state"] : never
> extends infer BoardResult extends GameState["board"]
	? {
			board: BoardResult;
			state: CheckState<{ board: BoardResult; state: Game["state"] }>;
		}
	: never;

type abcd = Transpose<NewGame["board"]>;
type ex = Connect4<NewGame, 0>["board"];
