type TicTacToeChip = "❌" | "⭕";
type TicTacToeEndState = "❌ Won" | "⭕ Won" | "Draw";
type TicTacToeState = TicTacToeChip | TicTacToeEndState;
type TicTacToeEmptyCell = "  ";
type TicTacToeCell = TicTacToeChip | TicTacToeEmptyCell;
type TicTacToeYPositions = "top" | "middle" | "bottom";
type TicTacToeXPositions = "left" | "center" | "right";
type TicTacToePositions = `${TicTacToeYPositions}-${TicTacToeXPositions}`;
type TicTactToeBoard = TicTacToeCell[][];
type TicTacToeGame = {
	board: TicTactToeBoard;
	state: TicTacToeState;
};

type EmptyBoard = [["  ", "  ", "  "], ["  ", "  ", "  "], ["  ", "  ", "  "]];

type NewGame = {
	board: EmptyBoard;
	state: "❌";
};

type YToIdx = {
  'top': 0,
  'middle': 1,
  'bottom': 2
}

type XToIdx = {
  'left': 0,
  'center': 1,
  'right': 2
}

type ModifyRow<Row extends TicTactToeBoard[number], Chip extends TicTacToeChip, XPos extends TicTacToeXPositions> =
  XPos extends 'left'
    ? Row extends [TicTacToeCell, ...infer Rest] ? [Chip, ...Rest] : never
    : XPos extends 'right'
      ? Row extends [...infer First, TicTacToeCell] ? [...First, Chip] : never
      : XPos extends 'center'
        ? Row extends [infer A extends TicTacToeCell, TicTacToeCell, infer B extends TicTacToeCell]
          ? [A, Chip, B]
          : never
        : never

type ModifyGame<Board extends TicTactToeBoard, NewPlacement extends TicTacToePositions, NewChip extends TicTacToeChip> =
  NewPlacement extends `${infer YPosStr extends TicTacToeYPositions}-${infer XPosStr extends TicTacToeXPositions}`
    ? Board[YToIdx[YPosStr]][XToIdx[XPosStr]] extends "  " ? {board: [
      YToIdx[YPosStr] extends 0 ? ModifyRow<Board[0], NewChip, XPosStr> : Board[0],
      YToIdx[YPosStr] extends 1 ? ModifyRow<Board[1], NewChip, XPosStr> : Board[1],
      YToIdx[YPosStr] extends 2 ? ModifyRow<Board[2], NewChip, XPosStr> : Board[2]
    ], state: NewChip} : {board: Board, state: OmitUnion<TicTacToeChip, NewChip>}
    : never;

type OmitUnion<A, B> = [A] extends [B | infer Rest] ? Rest : never

type GetColumn<Board extends TicTactToeBoard, Idx extends number> =
  Board extends []
    ? []
    : Board extends [infer First extends TicTactToeBoard[number], ...infer Rest extends TicTactToeBoard[number][]]
      ? [First[Idx], ...GetColumn<Rest, Idx>]
      : never

type Transpose<Board extends TicTactToeBoard, Cur extends TicTactToeBoard = []> =
  Cur['length'] extends Board['length']
    ? Cur
    : Transpose<Board, [...Cur, GetColumn<Board, Cur['length']>]>

type CheckWin<Board extends TicTactToeBoard> =
   ["⭕", "⭕", "⭕"] extends Board[number]
        ? "⭕"
        :  ["❌", "❌", "❌"] extends Board[number]
          ? "❌"
          : '  ' extends Board[number][number] ? never : false

type ModForWin<Game extends TicTacToeGame> =
  [(CheckWin<Game['board']> | CheckWin<Transpose<Game['board']>>)] extends [infer Result extends TicTacToeChip | false]
    ? [Result] extends [never] ? {
      board: Game['board'],
      state: OmitUnion<TicTacToeChip, Game['state']>
    } : Result extends false ? {
      board: Game['board'],
      state: "Draw"
    } : {
      board: Game['board'],
      state: `${Result} Won`
    }
    : never

type Exiii = ModForWin<{
  board: [["⭕", "❌", "  "], ["  ", "❌", "  "], ["⭕", "❌", "  "]],
  state: "❌"
}>

type TicTacToe<
	Game extends TicTacToeGame,
	Move extends TicTacToePositions,
> = Game['state'] extends TicTacToeEndState ? Game : ModForWin<ModifyGame<Game['board'], Move, Game['state'] extends TicTacToeChip ? Game['state'] : never>>;

type Ex = TicTacToe<NewGame, "top-center">
