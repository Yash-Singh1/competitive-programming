// TODO: Really inefficient solution, will come back to this later to make it better
// Instead of decrementing the number, we can probably just store the parts as arrays and wait for the lengths to match

type Dec = {
	'1': '0',
	'2': '1',
	'3': '2',
	'4': '3',
	'5': '4',
	'6': '5',
	'7': '6',
	'8': '7',
	'9': '8',
}
type DecrementStr<Num extends string> =
	Num extends `${infer N}0`
		? `${DecrementStr<N>}9`
		: Num extends `${infer First}${infer Last extends keyof Dec}`
			? `${First}${Dec[Last]}`
			: Num extends keyof Dec ? Dec[Num] : Num;
type Decrement<Num extends number> =
	Num extends 0
		? -1
		: `${Num}` extends `${infer NumStr extends string}` 
			? DecrementStr<NumStr> extends `${infer Ans extends number}`
				? Ans
				: never
			: never;

type Negative<N extends number> =
	`${N}` extends `-${infer Part extends number}`
		? Part
		: `-${N}` extends `${infer Part extends number}`
			? Part
			: never;

type Slice<Arr extends any[], Start extends number = 0, End extends number = Arr['length']> =
	Start extends (Start extends 0 ? 0 : (`-${Arr['length']}` extends `${infer PartAsNum extends number}` ? PartAsNum : 0))
		? End extends Arr['length']
			? Arr
			: End extends -1
				? Arr extends [...infer First, infer Rest]
					? First
					: []
			  : Arr extends [...infer First, infer Last]
					? Slice<First, `${Start}` extends `-${infer PartAsNum extends number}` ? (Start extends -1 ? Start : Negative<Decrement<PartAsNum>>) : (Start extends Arr['length'] ? Decrement<Start> : Start), `${End}` extends `-${infer PartAsNum extends number}` ? Negative<Decrement<PartAsNum>> : End>
					: Arr
		: End extends 0
			? []
			: Arr extends [infer First, ...infer Last]
				? Slice<Last, `${Start}` extends `-${infer PartAsNum extends number}` ? Start : Decrement<Start>, `${End}` extends `-${infer PartAsNum extends number}` ? End : Decrement<End>>
				: Arr;
