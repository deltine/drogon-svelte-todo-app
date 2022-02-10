import { serialize } from 'cookie';

/** @type {import('@sveltejs/kit').RequestHandler} */
export async function post({ body: { testToken } }) {
	console.log('test');
	console.log('testToken', testToken);

	const response = await fetch('https://jsonplaceholder.typicode.com/todos/1');
	let result = await response.json();
	console.log(result);

	const response2 = await fetch('http://localhost:80/web/Account/signin', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/x-www-form-urlencoded;'
		},
		body: new URLSearchParams({ mailAddress: 'mailAddress', password: 'password' }).toString()
	});
	let result2 = await response2.json();
	console.log(result2);

	return {
		status: 201
		// headers: {
		// 	"Set-Cookie": serialize('authToken', authToken, {
		// 		path: '/',
		// 		httpOnly: true,
		// 		sameSite: 'strict',
		// 		secure: process.env.NODE_ENV === 'production',
		// 		maxAge: 60 * 60 * 24 * 7, // one week
		// 	}),
		// }
	};
}
