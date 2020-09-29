<template>
    <div>
        <Header siteName="User List"></Header>
        <UserList></UserList>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../components/header/HeaderGlobal';
import UserList from '../components/content/UserList';
import Footer from '../components/footer/Footer';
export default {

  components: {
    Header,
    UserList,
    Footer
  }
}
</script>
