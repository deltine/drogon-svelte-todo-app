import { serialize } from 'cookie';
import { makeResetCoolie } from '@api/util';

/** @type {import('@sveltejs/kit').RequestHandler} */
export async function post(request) {
	let resCookie = makeResetCoolie(['authToken', 'authKey']);

	return {
		status: 200,
		headers: {
			...resCookie
		}
	};
}
