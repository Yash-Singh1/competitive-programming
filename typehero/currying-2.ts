type CurryGen<T extends any[], R extends any> =
	<T2 extends any[]>(...args: T2) => T2 extends T ? R : T extends [...T2, ...infer Rest] ? CurryGen<Rest, R> : R;

declare function DynamicParamsCurrying<T extends (...args: any[]) => any>(fn: T): CurryGen<Parameters<T>, ReturnType<T>>
