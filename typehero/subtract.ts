// Pretty simple since the problem asks for a tuple-based solution
// Larger than max depth is errored out in test cases

type BuildArray<A extends number, Ans extends 0[] = []> = Ans["length"] extends A
	? Ans
	: BuildArray<A, [...Ans, 0]>;

// M => minuend, S => subtrahend
type Subtract<M extends number, S extends number> = BuildArray<M> extends [...BuildArray<S>, ...infer Rest] ? Rest['length'] : never;
