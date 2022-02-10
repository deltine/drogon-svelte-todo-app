import { makeSetCookie } from './util';
import type { RequestHandler } from '@sveltejs/kit';
// import type { EndpointOutput, RequestEvent } from '@sveltejs/kit';

/** @type {import('@sveltejs/kit').RequestHandler} */
export const post: RequestHandler = async (event) => {
	// export async function post(event) {
	console.log('■drogon start:', new Date());
	// console.log('process.env.VITE_TEST_KEY', process.env.VITE_TEST_KEY);
	// console.log('event', event);
	// console.log('resource', event.request);
	const body = await event.request.json();
	// console.log('body', body);
	// console.log('body', event.request.body);

	let reqPath = body['path'];
	let reqHeaders = event.request.headers;
	let reqBody = body;
	delete reqBody['path'];

	console.log('reqPath', reqPath);
	console.log('reqBody', reqBody);
	// console.log('reqHeaders', reqHeaders);
	console.log('■drogon request');

	const response = await fetch('http://localhost:80/api/' + reqPath, {
		method: 'POST',
		headers: reqHeaders,
		body: JSON.stringify(reqBody)
	});

	if (!response.ok) {
		console.log('■drogon faild end');
		return {
			status: response.status
		};
	}

	let resBody = await response.json();
	console.log('resBodyRow', resBody);

	let resCookie = makeSetCookie({
		authKey: resBody.authKey,
		authToken: resBody.authToken
	});

	delete resBody.authKey;
	delete resBody.authToken;

	console.log('resBody', resBody);
	console.log('resCookie', resCookie);
	console.log('■drogon success end:', new Date());

	return {
		status: response.status,
		body: resBody,
		headers: {
			...resCookie
		}
	};
};
