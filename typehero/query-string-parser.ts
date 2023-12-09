type GetKeyVal<Portion extends string> = Portion extends `${infer Key}=${infer Value}` ? [Key, Value] : [Portion, true];
type IncludesSplit<Arr extends any[], Search extends any> = Arr extends [infer First, ...infer Rest]
	? First extends Search
		? [[], Rest]
		: [[First, ...IncludesSplit<Rest, Search>[0]], IncludesSplit<Rest, Search>[1]]
	: [[], []]

type ParseQueryString<S extends string> =
	S extends `${infer Portion}&${infer Rest}`
		? GetKeyVal<Portion> extends [infer Key, infer Value] ? {
			[Keys in string & Key | keyof ParseQueryString<Rest>]:
				Keys extends keyof ParseQueryString<Rest>
					? Keys extends Key
						? Value extends infer CurValue
								? ParseQueryString<Rest>[Keys] extends CurValue ?
										CurValue
								: ParseQueryString<Rest>[Keys] extends any[] ? IncludesSplit<ParseQueryString<Rest>[Keys], CurValue> extends [[], []] ? [
										Value,
										...(ParseQueryString<Rest>[Keys] extends any[] ? ParseQueryString<Rest>[Keys] : [ParseQueryString<Rest>[Keys]]),
									] : [CurValue, ...IncludesSplit<ParseQueryString<Rest>[Keys], CurValue>[0], ...IncludesSplit<ParseQueryString<Rest>[Keys], CurValue>[1]] : [
										Value,
										...(ParseQueryString<Rest>[Keys] extends any[] ? ParseQueryString<Rest>[Keys] : [ParseQueryString<Rest>[Keys]]),
									]
							: [
								Value,
								...(ParseQueryString<Rest>[Keys] extends any[] ? ParseQueryString<Rest>[Keys] : [ParseQueryString<Rest>[Keys]]),
							]
						: ParseQueryString<Rest>[Keys]
					: Value
		} : never : S extends '' ? {} : {
			[k in GetKeyVal<S>[0]]: GetKeyVal<S>[1]
		}

type Ex = ParseQueryString<'k1=v1&k1=v2&k1=v1'>
//   ^?
