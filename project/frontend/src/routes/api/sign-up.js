import { createSession, getUserByEmail, registerUser } from './db_bk';
import cookie, {serialize} from 'cookie';

/** @type {import('@sveltejs/kit').RequestHandler} */
export async function post({ body: { mailAddress, password } }) {

	console.log("sign-up");
	console.log("mailAddress", mailAddress);
	console.log("password", password);
	// console.log("password", password);

	// const response = await fetch('http://localhost:8080/web/Account/signup', {
	// 		method: 'POST',
	// 		headers: {
	// 			'Content-Type': 'application/x-www-form-urlencoded;'
	// 		},
	// 		body: new URLSearchParams({ mailAddress: mailAddress, password: password }).toString()
	// 	});

	// if (response.ok) {
	// 	console.log("response", response);
	// }

	// return {
	// 	status: 409,
	// 	body: {
	// 		message: 'User already exists',
	// 	},
	// };

	const response = await fetch('http://localhost:80/web/Account/signup', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/x-www-form-urlencoded;'
			},
			body: new URLSearchParams({ mailAddress: mailAddress, password: password }).toString()
		});
    // let result = await response.json();
    // console.log(result);
	console.log("signup response:", response);
	console.log("signup headers:", response.headers.get("Set-Cookie"));
	const cookies = cookie.parse(response.headers.get("Set-Cookie") || '');
	// console.log("signup headers:", cookies);
	// console.log("signup headers JSESSIONID:", cookies['JSESSIONID']);
	// console.log("signup headers drogonAuthKey:", cookies['drogonAuthKey']);
	// console.log("signup headers HttpOnly, drogonAuthKey:", cookies['HttpOnly, drogonAuthKey']);
	

	console.log(serialize(
		"JSESSIONID", cookies['JSESSIONID'],
		{
		path: '/',
		httpOnly: true,
		sameSite: 'strict',
		secure: process.env.NODE_ENV === 'production',
		maxAge: 60 * 60 * 24 * 7, // one week
	}));

	console.log(serialize(
		"authKey", cookies['HttpOnly, authKey'],
		{
		path: '/',
		httpOnly: true,
		sameSite: 'strict',
		secure: process.env.NODE_ENV === 'production',
		maxAge: 60 * 60 * 24 * 7, // one week
	}));
	// let res = await response;
	// let headers = response.headers.get("");

	return {
		status: response.status,
		headers: {
			"Set-Cookie": [
				serialize(
					"JSESSIONID", cookies['JSESSIONID'],
					{
					path: '/',
					httpOnly: true,
					sameSite: 'strict',
					secure: process.env.NODE_ENV === 'production',
					maxAge: 60 * 60 * 24 * 7, // one week
				}),
				serialize(
					"authToken", cookies['HttpOnly, authKey'],
					{
					path: '/',
					httpOnly: true,
					sameSite: 'strict',
					secure: process.env.NODE_ENV === 'production',
					maxAge: 60 * 60 * 24 * 7, // one week
				})
			]
		}
	}

	// return {
	// 	status: response.status,
	// 	headers: {
	// 		"Set-Cookie": serialize(
	// 			"JSESSIONID", cookies['JSESSIONID'],
	// 			{
	// 			path: '/',
	// 			httpOnly: true,
	// 			sameSite: 'strict',
	// 			secure: process.env.NODE_ENV === 'production',
	// 			maxAge: 60 * 60 * 24 * 7, // one week
	// 		}) + serialize(
	// 			"drogonAuthKey", cookies['HttpOnly, drogonAuthKey'],
	// 			{
	// 			path: '/',
	// 			httpOnly: true,
	// 			sameSite: 'strict',
	// 			secure: process.env.NODE_ENV === 'production',
	// 			maxAge: 60 * 60 * 24 * 7, // one week
	// 		})
			
	// 	}
	// }

	// return {
	// 	status: response.status,
	// 	body: {
			
	// 	},
	// 	headers: headers
	// }

	// return {
	// 	status: response.status,
	// 	{
	// 		Headers: {
	// 			path: '/',
	// 		}
	// 	}
	// };
	// let res = response;

	// if (!response.ok) {
	// 	return {
	// 		status: 500,
	// 	}
	// }

	// if (result.result == 0) {
	// 	return {
	// 		status: 201
	// 	}
	// }

	// let headers = response.headers;

	// return {
	// 	// status: 301,
	// 	...response.body,
	// 	headers: {
	// 		// headers,
	// 		path: '/',
			
	// 	}
	// return {
	// 	status: 201,
	// 	headers: {
	// 		"Set-Cookie": serialize('authToken', result.authToken, {
	// 			path: '/',
	// 			httpOnly: true,
	// 			sameSite: 'strict',
	// 			secure: process.env.NODE_ENV === 'production',
	// 			maxAge: 60 * 60 * 24 * 7, // one week
	// 		}),
	// 	}
	// }


	// return {
	// 	status: 201,
	// 	headers: {
	// 		// 'Set-Cookie': serialize('session_id', id, {
	// 		// 	path: '/',
	// 		// 	httpOnly: true,
	// 		// 	sameSite: 'strict',
	// 		// 	secure: process.env.NODE_ENV === 'production',
	// 		// 	maxAge: 60 * 60 * 24 * 7, // one week
	// 		// }),
	// 	},
	// 	body: {
	// 		message: 'Successfully signed up',
	// 	},
	// };











	// const user = await getUserByEmail(email);

	// if (user) {
	// 	return {
	// 		status: 409,
	// 		body: {
	// 			message: 'User already exists',
	// 		},
	// 	};
	// }

	// // ⚠️ CAUTION: Do not store a plain password like this. Use proper hashing and salting.
	// await registerUser({
	// 	email,
	// 	password,
	// });

	// const { id } = await createSession(authToken);
	// return {
	// 	status: 201,
	// 	headers: {
	// 		'Set-Cookie': serialize('session_id', id, {
	// 			path: '/',
	// 			httpOnly: true,
	// 			sameSite: 'strict',
	// 			secure: process.env.NODE_ENV === 'production',
	// 			maxAge: 60 * 60 * 24 * 7, // one week
	// 		}),
	// 	},
	// 	body: {
	// 		message: 'Successfully signed up',
	// 	},
	// };
}
