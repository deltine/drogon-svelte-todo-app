import cookie, { serialize } from 'cookie';
import { v4 as uuid } from 'uuid';
import type { Handle } from '@sveltejs/kit';
// import { goto } from '$app/navigation';

/**
 * リクエスト前に呼ばれるCookieもついてる
 * @param param0
 * @returns
 */
export const handle: Handle = async ({ request, resolve }) => {
	// console.log('Handle pathname', request.url.pathname);
	// console.log('Handle request', request);
	const response = await resolve(request);
	const cookies = cookie.parse(request.headers.cookie || '');

	// 停止
	return {
		...response
	};

	// 処理概要
	// オープンのサイトか？
	// オープンなら何もしない
	// プロテクトならログインチェックして未ログインならトップ画面へ

	// 未ログインのルーティング
	const publicPath = ['/', '/about'];

	if (publicPath.includes(request.url.pathname)) {
		console.log('オープンスペースにアクセス');
		// 処理無し

		// if (typeof request.headers.cookie === 'undefined') {
		// 	console.log('cookie無し');
		// 	// 無効ならLogin画面へ
		// } else {
		// 	// Cookieが有効ならTodo画面へ

		// 	// authToken確認
		// 	const responseCheckLogin = await fetch('http://localhost:80/web/Account/checkLogin', {
		// 		method: 'POST',
		// 		headers: {
		// 			'Content-Type': 'application/x-www-form-urlencoded;'
		// 		},
		// 		body: new URLSearchParams({ authToken: cookies.authToken }).toString()
		// 	});
		// 	let result = await responseCheckLogin.json();
		// 	console.log('result', result);
		// 	if (result.result == 0) {
		// 		// authToken無効
		// 		console.log('authToken無効');
		// 		return {
		// 			status: 302,
		// 			headers: {
		// 				location: '/',
		// 				'Set-Cookie': serialize('authToken', '', {
		// 					path: '/',
		// 					// httpOnly: true,
		// 					// sameSite: 'strict',
		// 					// secure: process.env.NODE_ENV === 'production',
		// 					expires: new Date(0)
		// 				})
		// 			}
		// 		};
		// 	}
		// }

		return {
			...response
		};
	}

	// ログインが必須のルーティング
	// 未ログインはトップ画面へ

	// クッキーを参照して無ければログイン画面へリダイレクト
	if (request.headers.cookie) {
		console.log('cookie無しtest');
	}
	if (typeof request.headers.cookie === 'undefined') {
		console.log('cookie無し');

		// return {
		// 	headers: {
		// 		location: '/',
		// 		'set-cookie': `token=${data}; SameSite=Strict; Max-Age=${tokenAge}`
		// 	},
		// 	status: 302
		// }

		return {
			headers: {
				location: '/'
			},
			status: 302
		};
	}

	const responseDrogon = await fetch('http://localhost:80/api/Account/checkLogin', {
		method: 'POST',
		headers: { ...request.headers },
		body: JSON.stringify(request.body)
	});

	let body = await responseDrogon.json();
	console.log('responseDrogon', responseDrogon);
	console.log('checkLogin result', body);

	if (body.result != 1) {
		console.log('checkLogin faild.');
		return {
			headers: {
				location: '/'
			},
			status: 302
		};
	}

	// if (typeof cookies.authToken === "undefined") {
	// 	// 未ログイン
	// 	return {
	// 		headers: {
	// 			location: '/',
	// 		},
	// 		status: 302
	// 	}
	// }

	// 以降
	// const cookies = cookie.parse(request.headers.cookie || '');
	// console.log("cookie", cookies);
	// // console.log("hools authToken", cookies.authToken);

	// if (typeof cookies.authToken === "undefined") {
	// 	// 未ログイン
	// 	return {
	// 		headers: {
	// 			location: '/',
	// 		},
	// 		status: 302
	// 	}
	// }

	// // authToken確認
	// const responseCheckLogin = await fetch('http://localhost:80/web/Account/checkLogin', {
	// 		method: 'POST',
	// 		headers: {
	// 			'Content-Type': 'application/x-www-form-urlencoded;'
	// 		},
	// 		body: new URLSearchParams({ authToken: cookies.authToken }).toString()
	// 	});
	// let result = await responseCheckLogin.json();
	// console.log(result);

	// if (!responseCheckLogin.ok) {
	// 	return {
	// 		...response,
	// 		status: 500,
	// 	}
	// }

	// if (result.result == 0) {
	// 	// Cookie無効
	// 	return {
	// 		status: 201,
	// 		headers: {
	// 			'Set-Cookie': serialize('session_id', '', {
	// 				path: '/',
	// 				expires: new Date(0),
	// 			}),
	// 		},
	// 	};
	// }

	// const response2 = await fetch('http://localhost:8080/web/Account/signup', {
	// 		method: 'POST',
	// 		headers: {
	// 			// 'Content-Type': 'application/x-www-form-urlencoded;'
	// 			'Content-Type': 'application/json'
	// 		},
	// 		body: new URLSearchParams({ mailAddress: "test1000@mail.jp", password: "password" }).toString()
	// 	});

	// const json = response2.json();
	// console.log("json", json);

	// console.log("handle request:", request);

	// const cookies = cookie.parse(request.headers.cookie || '');
	// request.locals.userid = cookies.userid || uuid();
	// console.log("handle request" ,request);

	// if (!cookies.userid) {
	// 	// if this is the first time the user has visited this app,
	// 	// set a cookie so that we recognise them when they return
	// 	response.headers['set-cookie'] = cookie.serialize('userid', request.locals.userid, {
	// 		path: '/',
	// 		httpOnly: true
	// 	});
	// }

	// return {
	// 	...response,
	// 	headers: {
	// 		...response.headers,
	// 		// helloWorld: "test massage"
	// 	}
	// }

	return {
		...response
	};
};

/**
 * リクエスト前に呼ばれるCookieもついてる
 * @param request
 * @returns
 */
export const getSession = async (request) => {
	// console.log('getSession request: ', request);
	// console.log("getSession request.locals: ", request.locals);
	// console.log('getSession', request.headers.cookie);

	if (request.headers.cookie == '') {
		return;
	}
	const cookies = cookie.parse(request.headers.cookie || '');
	// console.log('cookies', cookies);

	return {
		cookies
		// user: {
		// 	id: "testID",
		// 	name: "testName",
		// 	sccess: "admin"
		// }
	};
};
