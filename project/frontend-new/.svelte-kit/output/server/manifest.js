export const manifest = {
	appDir: "_app",
	assets: new Set(["favicon.png"]),
	_: {
		mime: {".png":"image/png"},
		entry: {"file":"start-329dedfe.js","js":["start-329dedfe.js","chunks/vendor-6d43d0bd.js"],"css":[]},
		nodes: [
			() => import('./nodes/0.js'),
			() => import('./nodes/1.js'),
			() => import('./nodes/2.js'),
			() => import('./nodes/3.js'),
			() => import('./nodes/4.js')
		],
		routes: [
			{
				type: 'page',
				pattern: /^\/$/,
				params: null,
				path: "/",
				shadow: null,
				a: [0,2],
				b: [1]
			},
			{
				type: 'page',
				pattern: /^\/about\/?$/,
				params: null,
				path: "/about",
				shadow: null,
				a: [0,3],
				b: [1]
			},
			{
				type: 'page',
				pattern: /^\/todo\/?$/,
				params: null,
				path: "/todo",
				shadow: null,
				a: [0,4],
				b: [1]
			},
			{
				type: 'endpoint',
				pattern: /^\/api\/drogon\/?$/,
				params: null,
				load: () => import('./entries/endpoints/api/drogon.ts.js')
			},
			{
				type: 'endpoint',
				pattern: /^\/api\/test1\/?$/,
				params: null,
				load: () => import('./entries/endpoints/api/test1.ts.js')
			},
			{
				type: 'endpoint',
				pattern: /^\/api\/test\/?$/,
				params: null,
				load: () => import('./entries/endpoints/api/test.ts.js')
			},
			{
				type: 'endpoint',
				pattern: /^\/api\/util\/?$/,
				params: null,
				load: () => import('./entries/endpoints/api/util.ts.js')
			}
		]
	}
};
