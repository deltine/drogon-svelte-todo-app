<script context="module">
	// import { getCookie } from '../api/util';

	export async function load({ session }) {
		console.log('todo session', session);

		// if (!session?.cookies?.authToken) {
		// 	return {
		// 		status: 302,
		// 		redirect: '/'
		// 	};
		// }

		// let authToken = getCookieValue('authToken');
		// console.log('authToken', authToken);

		// return {
		// 	// props: {
		// 	// 	user: session.user
		// 	// }
		// };

		// let authToken = getCookie('authToken');
		// console.log('todo/index authToken', authToken);

		return {
			props: {
				session
			}
		};
	}
</script>

<script>
	import Nav from '@lib/header/nav.svelte';
	import Footer from '@lib/footer.svelte';
	import LoginForm from '@lib/loginForm.svelte';
</script>

<svelte:head>
	<title>Home</title>
</svelte:head>

<div class="min-h-screen flex flex-col">
	<Nav />
	<section class="flex flex-col flex-1 overflow-hidden min-h-max">
		<div class="flex flex-1 overflow-hidden">todo</div>
	</section>
	<Footer />
</div>
